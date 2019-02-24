#include <avr/io.h>
#include "F90_SPI.h"























void F90_void_SPI_init(char mode)
{

	unsigned char reg = 0 ;
	switch(mode)
	{
	case MASTER:
		SET_BIT(DDRB , PB5);					//MOSI
		SET_BIT(DDRB , PB7);					//SCK
		SET_BIT(DDRB , PB4);					//SS
		SET_BIT(DDRB , PB3);					//SS
		SET_BIT(reg , SPE);
		SET_BIT(reg , SPR0);
		SET_BIT(reg , MSTR);
		SPCR = reg;
		break;
	case SLAVE:
		SET_BIT(DDRB , PB6);					//MISO
		SET_BIT(reg , SPE);
		SPCR = reg;
		break;

	}

}


void F90_void_SPI_Transmit(char data , char num)
{
	if(num == 1)
	{
		SET_BIT(PORTB , PB4);					//SS
		CLEAR_BIT(PORTB , PB3);					//SS
	}
	else if (num == 2)
	{
		CLEAR_BIT(PORTB , PB4);					//SS
		SET_BIT(PORTB , PB3);					//SS
	}

	SPDR = data;
	while(!READ_BIT(SPSR , SPIF));
}



char F90_char_SPI_Receive(void)
{
	while(!READ_BIT(SPSR , SPIF));

	return SPDR ;

}

