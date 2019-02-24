/*
 * Special_Uart.h
 *
 *  Created on: 9 Feb 2019
 *      Author: root
 */

#ifndef SERVICES_LAYERS_SPECIAL_UART_H_
#define SERVICES_LAYERS_SPECIAL_UART_H_

#define CHANGE "we"
#define UART_TIMEOUT_READ	5

void SpecialUart_Init();
void SpecialUart_Update(void);
int SpecialUart_read_array(char *arr);
int SpecialUart_Queue_getsize(void);


#endif /* SERVICES_LAYERS_SPECIAL_UART_H_ */
