

#include "../MCAL/F91_DIO.h"
#include "../Services_layers/Services_layers.h"
#include "F91_Button.h"


void F91_void_Init_Buttons()
{
	F91_void_Initpin('A' , 0 , INPUT);
	F91_void_Initpin('D' , 2 , INPUT);

	F91_void_Writpin('A' , 0 , HIGH);
	F91_void_Writpin('D' , 2 , HIGH);


}


char F91_char_ReadButton_1()
{
	return F91_char_Readpin('A' , 0);
}
char F91_char_ReadButton_2()
{
	return F91_char_Readpin('D' , 2);
}
