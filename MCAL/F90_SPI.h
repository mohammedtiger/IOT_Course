/*
 * F90_SPI.h
 *
 *  Created on: Sep 12, 2018
 *      Author: root
 */

#ifndef F90_SPI_H_
#define F90_SPI_H_

#define SET_BIT(REG , BIT) (REG |= (1 << BIT))
#define CLEAR_BIT(REG , BIT) (REG &= ~(1 << BIT))
#define READ_BIT(REG , BIT) (REG & (1 << BIT))

enum
{
	MASTER,
	SLAVE
};

void F90_void_SPI_init(char mode);
void F90_void_SPI_Transmit(char data , char num);
char F90_char_SPI_Receive(void);




#endif /* F90_SPI_H_ */
