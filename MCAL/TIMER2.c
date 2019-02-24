
#include "TIMER2.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void (*ptr_func)(void);

void Timer2_Init(void)
{
	TCCR2 = (1 << CS22);
	TIMSK |= (1 << TOIE2);
	sei();
}

void Timer2_callbackfunc( void (*ptr) (void))
{
	ptr_func = ptr;
}


ISR(TIMER2_OVF_vect)
{
	if(ptr_func)
		ptr_func();

}
