
#include "Special_Uart.h"
#include "Speical_Timer.h"
#include "../MCAL/F90_UART.h"
#include "Services_layers.h"
#include "String_Queue.h"
#include "../MCAL/F91_TIMER0.h"

#include <avr/delay.h>
#include <avr/io.h>
#include <string.h>

string_queue_t Uart_String;
unsigned char data[ELEMENT_SIZE];

int mqtt_flag = 0;

void SpecialUart_Update(void)
{
	if(Uart_Queue_GetSize())
	{
		SpecialTimer_Start(UART);
	}

	if(SpecialTimer_Check(UART , UART_TIMEOUT_READ))
	{
		while(Uart_Queue_GetSize())
		{
			int index;
			for(index = 0 ;Uart_Queue_GetSize(); index ++)
			{

//				if(index > sizeof(CHANGE)-1)
//				{
//					if(!memcmp((&data[index- sizeof(CHANGE)+1])  , CHANGE , sizeof(CHANGE)-1))
//					{
//
//						index = index - sizeof(CHANGE) + 1 ;
//						break;
//					}
//				}

				data[index] = Uart_Read_Queue();

			}
			String_Queue_enqueue(&Uart_String , data , index);

		}
		SpecialTimer_Reset(UART);
		SpecialTimer_Stop(UART);
	}
}


void SpecialUart_Init()
{
	F91_void_TIMER0_init();
	Timer0_CallBackFunc(SpecialUart_Update);
}





int SpecialUart_read_array(char *arr)
{
	int size = 0 ;
	if (String_Queue_getsize(&Uart_String))
	{
		String_Queue_dequeue(&Uart_String , arr , &size);
		mqtt_flag = true;
	}

	return size;
}


int SpecialUart_Queue_getsize(void)
{
	return String_Queue_getsize(&Uart_String);
}













