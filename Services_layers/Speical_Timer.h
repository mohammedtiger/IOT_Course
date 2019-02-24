/*
 * Speical_Timer.h
 *
 *  Created on: 8 Feb 2019
 *      Author: root
 */

#ifndef SERVICESpecialTimerLAYERSpecialTimerSPEICAL_TIMER_H_
#define SERVICESpecialTimerLAYERSpecialTimerSPEICAL_TIMER_H_


enum
{
	LED7_TIMER,
	LED6_TIMER,
	UART,
	ATCOMMANDER_TIMEOUT,
	TIMER0_COUNTER_NUMBER
};


void SpecialTimer_Init();
void SpecialTimer_Reset(char index);
void SpecialTimer_Start(char index);
void SpecialTimer_Stop(char index );
char SpecialTimer_Check(char index , unsigned long compare);



#endif /* SERVICESpecialTimerLAYERSpecialTimerSPEICAL_TIMER_H_ */
