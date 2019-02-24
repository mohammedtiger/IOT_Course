


#include "F90_UART.h"
#include "avr/io.h"
#include "util/delay.h"
#include <avr/interrupt.h>
#include "../Services_layers/Queue.h"
#include "../Services_layers/Speical_Timer.h"

Queue_t   Queue_Uart;

void F90_void_UART_init(unsigned long baud)
{
	UCSRB = 0;
	UCSRC = 0;
	UCSRA = 0;
	UBRRH = 0;
	UBRRL = 0;
	unsigned char reg = 0;
	unsigned long baudrate = (F_CPU / (16 * baud))- 1 ;
	UBRRH = (unsigned char)(baudrate >> 8);
	UBRRL = (unsigned char)baudrate;

	SET_BIT(reg , RXEN);
	SET_BIT(reg , TXEN);
	SET_BIT(reg , RXCIE);
	UCSRB = reg;
	reg = 0;

	SET_BIT(reg , URSEL);
	SET_BIT(reg , UCSZ0);
	SET_BIT(reg , UCSZ1);


	UCSRC = reg;


	sei();

}


void F90_void_UART_Write(char data)
{
	while(!(READ_BIT(UCSRA , UDRE)));
	UDR = (unsigned char)data;
}


void F90_void_UART_Write_Array(char *arr , int size)
{
	for(int index = 0 ; index < size ; index ++)
	{
		F90_void_UART_Write(arr[index]);
	}
}







void F90_void_UART_SendString(char *arr)
{
	int i = 0;
	while (arr[i] != 0)
	{
		F90_void_UART_Write(arr[i]);
		i++;
	}
}










char F90_char_UART_Read()
{
	while(!(READ_BIT(UCSRA , RXC)));
	return UDR;
}

unsigned char Uart_Read_Queue()
{
	unsigned char data = 0;

	Queue_Dequeue(&Queue_Uart , &data);

	return data ;
}

int Uart_Queue_GetSize()
{
	return Queue_getSize(&Queue_Uart);
}


ISR(USART_RXC_vect)
{
	SpecialTimer_Reset(UART);
	Queue_Enqueue(&Queue_Uart , UDR);
}
