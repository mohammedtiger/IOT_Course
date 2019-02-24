/*
 * F90_TIMER_0.c
 *
 *  Created on: Sep 7, 2018
 *      Author: root
 */
#include "F90_TIMER_0.h"
#include "avr/io.h"
#include "avr/interrupt.h"

volatile unsigned long Timer0_counter = 0;

void F90_void_Timer0_Init()
{

	SET_BIT(TIMER0_CONTROL_REG , CS01);
	SET_BIT(TIMER0_CONTROL_REG , CS00);
	SET_BIT(TIMER0_INT_REG , TOIE0);
	sei();

}

void F90_void_Timer0_Delay(unsigned long delay)
{
	Timer0_counter = 0;
	while(Timer0_counter < delay);
}

//ISR(TIMER0_OVF_vect)
//{
//	Timer0_counter++;
//}
