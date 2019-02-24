/*
 * F90_Temperature.h
 *
 *  Created on: Sep 15, 2018
 *      Author: root
 */

#ifndef F90_TEMPERATURE_H_
#define F90_TEMPERATURE_H_

enum
{
	ADC_PIN_TEMP = 1,
	ADC_PIN_LDR = 0

};

int F90_int_Temp_Read();
int F90_int_LDR_Read();


#endif /* F90_TEMPERATURE_H_ */
