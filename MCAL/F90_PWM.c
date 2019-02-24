
#include "F90_PWM.h"
#include "../MCAL/F91_DIO.h"
void F90_void_PWM_init()
{
	F91_SETBIT(TCCR0 , CS01);
	F91_SETBIT(TCCR0 , CS00);
	F91_SETBIT(TCCR0 , WGM01);
	F91_SETBIT(TCCR0 , WGM00);
	F91_SETBIT(TCCR0 , COM01);

	F91_SETBIT(DDRB , PB3);


}

void F90_void_PWM_Set(unsigned char value)
{
	OCR0 = value;
}


