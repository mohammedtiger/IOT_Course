
#include "../MCAL/F91_ADC.h"
#include "F90_Temperature.h"



int F90_int_Temp_Read()
{
	int temp = F91_int_ADC_Read(ADC_PIN_TEMP);
	return (temp * 4.88)/10;
}


int F90_int_LDR_Read()
{
	return F91_int_ADC_Read(ADC_PIN_LDR);
}
