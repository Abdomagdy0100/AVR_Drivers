/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include"LIB/STD_TYPES.h"
#include"DIO_int.h"
#include"KPD_interface.h"

#include"LCD_int.h"

/******************************************************/
/****************DONT FORGET TO T3DEEL************************/
/******************************************************/

void main(void)
{
	u8 x;

	DIO_SetPortDirection(DIO_PORTA, DIO_OUTPUT);
	DIO_SetPortDirection(DIO_PORTD, DIO_OUTPUT);

	/*set the pull up resistor for 4-input rows lines*/
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);

	/*set  4-input rows lines as inputs connected to pull up*/
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_INPUT);

	/*set  4-output cols lines as outputs */
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_OUTPUT);

	LCD_vidInit();

	//LCD_vidWriteString("AKHIRAN");




	while(1)
	{
		x=KPD_U8_GetKeyPressed();

		if(x != NotPressd)
		{
			LCD_vidWriteData(x);
		}
	}


}


