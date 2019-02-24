/*
 * F90_PWM.h
 *
 *  Created on: Sep 15, 2018
 *      Author: root
 */

#ifndef F90_PWM_H_
#define F90_PWM_H_
#include <avr/io.h>

#define TIMER2_CONTROL_REG 		TCCR0
#define TIMER2_INT_REG 			TIMSK

void F90_void_PWM_Set(unsigned char value);
void F90_void_PWM_init();

#endif /* F90_PWM_H_ */
