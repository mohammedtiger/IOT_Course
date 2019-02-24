
#include "F96_PWM.h"
#include <avr/io.h>
#include "../Services_layers/Services_layers.h"
#include "F91_DIO.h"


void F96_void_init_PWM()
{
	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM00) | (1 << COM01) | (1 << CS01) | (1 << CS00);
	F91_void_Initpin('b' , 3 , OUTPUT);
}

void F96_void_Write_pwm(int pwm)
{
	OCR0 = pwm;
}
