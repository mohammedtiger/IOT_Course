
#include <avr/interrupt.h>
#include "F90_I2C.h"

void F90_void_I2C_init()
{
	TWBR = 0x47;
	TWSR = 0x00;
	TWCR = (1 << TWEN);
}






void F90_void_I2C_Start()
{

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1<<TWEN);

	while(!(TWCR & (1 << TWINT)));

}

void F90_void_I2C_Stop()
{
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1<<TWEN);
}


void F90_void_I2C_Write(char data)
{
	TWDR = data ;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1 << TWINT)));
}




char F90_char_I2C_Read(char ack)
{
	if(ack)
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1 << TWEA);

	}
	else
	{
		TWCR = (1<<TWINT) | (1<<TWEN);

	}
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}
