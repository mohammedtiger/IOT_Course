/*
 * F90_TIMER_0.h
 *
 *  Created on: Sep 7, 2018
 *      Author: root
 */

#ifndef F90_TIMER_0_H_
#define F90_TIMER_0_H_

#define TIMER0_CONTROL_REG 		TCCR0
#define TIMER0_INT_REG 			TIMSK



#define SET_BIT(REG , BIT) (REG |= (1 << BIT))
#define CLEAR_BIT(REG , BIT) (REG &= ~(1 << BIT))
#define READ_BIT(REG , BIT) (REG & (1 << BIT))

extern volatile unsigned long Timer0_counter;

void F90_void_Timer0_Init();
void F90_void_Timer0_Delay(unsigned long delay);



#endif /* F90_TIMER_0_H_ */
