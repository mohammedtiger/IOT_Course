

#include <avr/io.h>
#include <avr/interrupt.h>
#include "F91_TIMER0.h"
#include "../Services_layers/Services_layers.h"
#include "../HAL/F91_Leds.h"

void (*Func_ptr)(void);


void F91_void_TIMER0_init()
{
	TCCR0 = (1 << CS00)| (1 << CS02);
	TIMSK |= (1 << TOIE0);
	sei();
}

void Timer0_CallBackFunc( void(*ptr)(void) )
{
	Func_ptr = ptr;
}


ISR(TIMER0_OVF_vect)
{
	if(Func_ptr)
		Func_ptr();
}
