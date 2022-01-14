/*
 * LCD_prog.c

 *
 *  Created on: Aug 17, 2018
 *      Author: seif
 */
/***********************HEader file Inclusion******************************/
#include "LIB/STD_TYPES.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_int.h"


void LCD_vidInit(void)
{
	/*Delay 30 ms to ensure the initilization of the LCD driver*/
	_delay_ms(30);
	/*Function set command*/
	LCD_vidSendCommand(LCD_FUNCSET_8BIT);
	_delay_ms(1);
	/* Display ON OFF control*/
	LCD_vidSendCommand(LCD_DISPON_CURSOFF);
	_delay_ms(1);
	/* Return Home  */
	LCD_vidSendCommand(LCD_HOME);
	_delay_ms(15);
	LCD_vidSendCommand(LCD_CLR);
	_delay_ms(15);
	/* Entry Mode Set  */
	LCD_vidSendCommand(LCD_ENTRYMODE);
	_delay_ms(2);

}

void LCD_vidSendCommand(u8 u8CmdCpy)
{
	/* Reset RS pin */
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	/* Reset R/W pin*/
	DIO_SetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
	/* Set E to HIGH  */
	DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
	/*Load command on data bus*/
	DIO_SetPortValue(DIO_PORTD, u8CmdCpy);

	DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);
	_delay_ms(5);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}
void LCD_vidWriteData(u8 u8DataCpy)
{
	/* Reset RS pin */
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	/* Reset R/W pin*/
	DIO_SetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
	/* Set E to HIGH  */
	DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
	/*Load command on data bus*/
	DIO_SetPortValue(DIO_PORTD, u8DataCpy);

	DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);
	_delay_ms(5);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);


}

void LCD_vidWriteString(u8* pu8StringCpy)
{
	u8 i=0;
	while (pu8StringCpy[i]!='\0')
	{
		LCD_vidWriteData(pu8StringCpy[i]);
		i++;
	}
}

void LCD_vidGotoXY(u8 u8Col_XCpy, u8 u8Row_YCpy)
{
	u8 address;
	if(u8Col_XCpy==0)
	{
		address=u8Row_YCpy;
	}
	else if(u8Col_XCpy==1)
	{
		address=u8Row_YCpy+0x40;
	}
	LCD_vidSendCommand(address+128);
}

void LCD_vidWriteCustomChar(u8* pattern, u8 pattern_number,u8 u8Col_XCpy, u8 u8Row_YCpy)
{
	u8 local_CGram_add=0,iterat;

	local_CGram_add = pattern_number*8;

	LCD_vidSendCommand(local_CGram_add+64);

	for(iterat=0;iterat<8;iterat++)
	{
		LCD_vidWriteData(pattern[iterat]);
	}

	LCD_vidGotoXY(u8Col_XCpy,u8Row_YCpy);

	LCD_vidWriteData(pattern_number);
}






