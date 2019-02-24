

#include "../MCAL/F91_DIO.h"
#include "F91_7Seg.h"
#include "../Services_layers/Services_layers.h"




void F91_void_Init7Seg(char port)
{

	F91_void_InitPort(_7SEGDATA_PORT , _7SEGDATA_PINS );

	F91_void_Writpin(_7SEG1_PORT , _7SEG1_PIN , HIGH);
	F91_void_Writpin(_7SEG2_PORT , _7SEG2_PIN , HIGH);
	F91_void_Writpin(_7SEG3_PORT , _7SEG3_PIN , HIGH);
	F91_void_Writpin(_7SEG4_PORT , _7SEG4_PIN , HIGH);

	switch (port)
	{
	case _7SEG1:
		F91_void_Initpin(_7SEG1_PORT , _7SEG1_PIN , OUTPUT);
		F91_void_Writpin(_7SEG1_PORT , _7SEG1_PIN , LOW);
		break;
	case _7SEG2:
		F91_void_Initpin(_7SEG2_PORT , _7SEG2_PIN , OUTPUT);
		F91_void_Writpin(_7SEG2_PORT , _7SEG2_PIN , LOW);

		break;
	case _7SEG3:
		F91_void_Initpin(_7SEG3_PORT , _7SEG3_PIN , OUTPUT);
		F91_void_Writpin(_7SEG3_PORT , _7SEG3_PIN , LOW);

		break;
	case _7SEG4:
		F91_void_Initpin(_7SEG4_PORT , _7SEG4_PIN , OUTPUT);
		F91_void_Writpin(_7SEG4_PORT , _7SEG4_PIN , LOW);

		break;

	}
}

void F91_void_7SegWrite(char value)
{
	F91_void_WritePort(_7SEGDATA_PORT , value);
}


