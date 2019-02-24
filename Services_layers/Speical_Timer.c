
#include "Services_layers.h"
#include "Speical_Timer.h"
#include "../MCAL/TIMER2.h"
#include "../MCAL/F91_TIMER0.h"

volatile unsigned long Counter_S_Timer[TIMER0_COUNTER_NUMBER];
unsigned char Counter_S_Timer_flag[TIMER0_COUNTER_NUMBER];

static void SpecialTimer_update(void)
{
	for(int index = 0 ; index < TIMER0_COUNTER_NUMBER ; index ++)
	{
		if(Counter_S_Timer_flag [index] )
			Counter_S_Timer[index]++;
	}
}

void SpecialTimer_Init()
{
	Timer2_Init();
	Timer2_callbackfunc(SpecialTimer_update);


}



void SpecialTimer_Reset(char index)
{
	if(index < TIMER0_COUNTER_NUMBER)
		Counter_S_Timer[index] = 0;
}


void SpecialTimer_Start(char index)
{
	if(index < TIMER0_COUNTER_NUMBER)
		Counter_S_Timer_flag[index] = true;
}

void SpecialTimer_Stop(char index )
{
	if(index < TIMER0_COUNTER_NUMBER)
		Counter_S_Timer_flag[index] = false;
}

char SpecialTimer_Check(char index ,unsigned long compare)
{
	if(index < TIMER0_COUNTER_NUMBER)
		return !(compare > Counter_S_Timer[index]);
	else
		return ERROR;
}
