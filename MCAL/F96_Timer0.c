
#include "F96_Timer0.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../HAL/F91_Leds.h"
#include "../Services_layers/Services_layers.h"

volatile unsigned long timer0_counter = 0;

void F96_void_Timer0_Init()
{
	TCCR0 = (1 << CS01) | (1 << CS00);   // prescaler set
	TIMSK = (1 << TOIE0);				 // enable interuppt mask
	sei();								 // globle int
	F91_void_InitLeds(LED1PIN);
}


//ISR(TIMER0_OVF_vect)
//{
//	timer0_counter++;
//
//	if(timer0_counter > 1000)
//	{
////		F91_void_WriteLeds(LED1PIN , LOW);
//		PORTA ^= (1 << LED1PIN);
//		timer0_counter = 0;
//	}
//
//}
