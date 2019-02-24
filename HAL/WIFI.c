
#include "../Services_layers/Special_Uart.h"
#include "../Services_layers/Speical_Timer.h"
#include "../Services_layers/String_Queue.h"
#include "../MCAL/F90_UART.h"
#include "WIFI.h"
#include <string.h>
#include <stdio.h>
#include "../Services_layers/Services_layers.h"
#include "avr/delay.h"

string_queue_t WIFI_STRING_QUEUE;

extern int mqtt_flag;

void WIFI_Init(void)
{
	F90_void_UART_init(9600);
	SpecialTimer_Init();
	SpecialUart_Init();


}

int WIFI_Send_Arr(const byte *arr , int size)
{
	F90_void_UART_Write_Array((char *)arr, size);
	return size;
}

int WIFI_Send_Byte(const byte *arr , int size)
{
	F90_void_UART_Write(arr[size]);
	return true;
}


int WIFI_Receive(char *arr)
{
	return SpecialUart_read_array(arr);
}


int WIFI_Rounter_Connect(char *ssid , char *pass , long timeout)
{

	char arr[50];
	memset(arr , 0 , sizeof(arr));
	int size1 = sprintf(arr , "ATE0\r\n" );

	WIFI_Send_Arr(arr , size1);

	WIFI_ATCOMMAND_DELAY(timeout/10);

	WIFI_Receive(arr);

	int size = sprintf(arr , "AT+CWJAP=\"%s\",\"%s\"\r\n" , ssid , pass);

	WIFI_Send_Arr(arr , size);


	WIFI_ATCOMMAND_DELAY(timeout);

	while(SpecialUart_Queue_getsize())
	{
		WIFI_Receive(arr);
	}

	if(!memcmp(arr , "\r\nOK\r\n" , sizeof("\r\nOK\r\n")))
		return true;
	else
		return false;

}

int WIFI_IP_Connect(char *protocol,const char*IP , int port , long timeout)
{

	char arr[50];
	memset(arr , 0 , sizeof(arr));

	int size = sprintf(arr , "AT+CIPSTART=\"%s\",\"%s\",%d\r\n" ,protocol, IP , port);

	WIFI_Send_Arr(arr , size);

	WIFI_ATCOMMAND_DELAY(timeout);

	while(SpecialUart_Queue_getsize())
	{
		WIFI_Receive(arr);
	}

	if(!memcmp(arr , "\r\nOK\r\n" , sizeof("\r\nOK\r\n")))
		return true;
	else
		return false;

}

int WIFI_IP_Send(char *data , int len ,  long timeout)
{

	char arr[50];
	memset(arr , 0 , sizeof(arr));


	int size = sprintf(arr , "AT+CIPSEND=%d\r\n" ,len);

	WIFI_Send_Arr(arr , size);

	WIFI_ATCOMMAND_DELAY(timeout);

	WIFI_Send_Arr(data , len);

	return true;


	//	while(SpecialUart_Queue_getsize())
	//	{
	//		WIFI_Receive(arr);
	//	}

	//	if(!memcmp(arr , "\r\nOK\r\n" , sizeof("\r\nOK\r\n")))
	//		return true;
	//	else
	//		return false;

}



void WIFI_ATCOMMAND_DELAY(long timeout)
{

	SpecialTimer_Start(ATCOMMANDER_TIMEOUT);
	while(!SpecialTimer_Check(ATCOMMANDER_TIMEOUT , timeout));
	mqtt_flag = false;
	SpecialTimer_Stop(ATCOMMANDER_TIMEOUT);
	SpecialTimer_Reset(ATCOMMANDER_TIMEOUT);
}


void WIFI_Select_Data(char *arr , int size )
{
	int len = 0;
	int last_len = 0;
	do
	{

		last_len = len;
		len = WIFI_Receive(arr);
		if(len)
		{
			for(int index = 0 ; index < len ; index ++)
			{
				if(arr[index] == ':')
				{
					String_Queue_enqueue(&WIFI_STRING_QUEUE , &arr[index + 1] , size);

					return;
				}
			}

		}
	}while(len);


}

int WIFI_Read_Data(char *arr , int size)
{
	int new_len = 0;
	WIFI_Select_Data(arr , size);
	String_Queue_dequeue(&WIFI_STRING_QUEUE , arr , &new_len);

	return new_len;
}


void WIFI_QUEUE_FLUSH()
{
	char arr[ELEMENT_SIZE];
	int len = 0;
	for(;String_Queue_getsize(&WIFI_STRING_QUEUE);)
	{
		String_Queue_dequeue(&WIFI_STRING_QUEUE , arr , &len);
	}
	for(;SpecialUart_Queue_getsize();)
	{
		WIFI_Receive(arr);
	}
}



void EF_Number_to_String(unsigned char * u8NumberArray, unsigned char u8NumberArraySize, unsigned char * u8StringArray, unsigned char u8StringArraySize)
{
	unsigned char u8NumberCounter = 0;
	unsigned char u8StrCounter    = 0;


	for(u8NumberCounter = 0; u8NumberCounter < u8NumberArraySize; u8NumberCounter++)
	{
		u8StringArray[u8StrCounter]     = ((u8NumberArray[u8NumberCounter ] & 0xF0) >> 4);  /* Assign the HSB half byte into its corresponding location in the string array */
		u8StringArray[u8StrCounter + 1] = (u8NumberArray[u8NumberCounter ] & 0x0F);         /* Assign the MSB half byte into its corresponding location in the string array */
		if(u8StringArray[u8StrCounter] > 9)
		{
			u8StringArray[u8StrCounter] += 55;     /* Convert integers from A to F to Ascii */
		}
		else
		{
			u8StringArray[u8StrCounter] += 48;     /* Convert integers from 0 to 9 to Ascii */
		}
		if(u8StringArray[u8StrCounter + 1] > 9)
		{
			u8StringArray[u8StrCounter + 1] += 55; /* Convert integers from A to F to Ascii */
		}
		else
		{
			u8StringArray[u8StrCounter + 1] += 48; /* Convert integers from 0 to 9 to Ascii */
		}
		u8StrCounter += 2;                         /* Increment the index to poin to the next half byte in the string array */
#ifndef USING_IMEI
		if(u8StrCounter == 8 || u8StrCounter == 13 || u8StrCounter == 18 || u8StrCounter == 23)
		{
			u8StringArray[u8StrCounter] = 45;
			u8StrCounter++;
		}
#endif
	}
}
