/*
 * F91_7Seg.h
 *
 *  Created on: Sep 3, 2018
 *      Author: root
 */

#ifndef F91_7SEG_H_
#define F91_7SEG_H_


enum
{
	_7SEG1_PORT='A',
	_7SEG2_PORT='A',
	_7SEG3_PORT='B',
	_7SEG4_PORT='C',
	_7SEGDATA_PORT='B'
};

enum
{
	_7SEG1_PIN=4,
	_7SEG2_PIN=3,
	_7SEG3_PIN=4,
	_7SEG4_PIN=4,
	_7SEGDATA_PINS=0x0F
};

enum
{
	_7SEG1,
	_7SEG2,
	_7SEG3,
	_7SEG4
};

void F91_void_Init7Seg(char port);
void F91_void_7SegWrite(char value);



#endif /* F91_7SEG_H_ */
