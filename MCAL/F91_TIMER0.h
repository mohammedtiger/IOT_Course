/*
 * F91_TIMER0.h
 *
 *  Created on: Sep 12, 2018
 *      Author: root
 */

#ifndef F91_TIMER0_H_
#define F91_TIMER0_H_

extern volatile unsigned long counter;
volatile unsigned long counter1;


void F91_void_TIMER0_init();
void Timer0_CallBackFunc( void(*ptr)(void) );



#endif /* F91_TIMER0_H_ */
