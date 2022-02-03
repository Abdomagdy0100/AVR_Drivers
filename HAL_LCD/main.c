/*
 * main.c
 *
 *  Created on: Aug 17, 2018
 *      Author: seif
 */

#include "LIB/types.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "LCD_int.h"


void main(void)
{
	/*Initialization*/

	DIO_SetPortDirection(DIO_PORTA, DIO_OUTPUT);
	DIO_SetPortDirection(DIO_PORTD, DIO_OUTPUT);

	LCD_vidInit();
	u8 p;
	u8 pattern1[8]=			//space alien
		{
			0b00001110,
			0b00011111,
			0b00010101,
			0b00011111,
			0b00001110,
			0b00000100,
			0b00000000,
		};
	u8 pattern2[8]=			//man
			{
				0b00001110,
				0b00001110,
				0b00000100,
				0b00011111,
				0b00000100,
				0b00001010,
				0b00010001,
			};

	//LCD_vidWriteCustomChar(pattern2,2,0,4); //man
	//LCD_vidWriteCustomChar(pattern1,3,1,6);  //space alien
	while(1)
	{
		LCD_vidSendCommand(0x01); 							//clear
		LCD_vidGotoXY(0,4); 								//position
		LCD_vidWriteString("HALLOWIN");
		_delay_ms(3000);
		LCD_vidSendCommand(0x01); 							//clear


		for(u8 i=0;i<19;i++)
		{
		LCD_vidWriteCustomChar(pattern2,2,0,i);  			//man
		_delay_ms(15);
		LCD_vidSendCommand(0x01);
			if(i==17)
			{
				for(u8 s=0;s<17;s++)
				{
					LCD_vidWriteCustomChar(pattern1,3,0,s); //space alien
					_delay_ms(15);
					LCD_vidSendCommand(0x01);
				}
			}

		}
		for(p=0;p<17;p++)
		{
			LCD_vidGotoXY(0,p); 								//position
			LCD_vidWriteString("BODY ^_^");
			_delay_ms(15);
			LCD_vidSendCommand(0x01);

		}
		LCD_vidWriteString("7L2 3LEH Y3M BAKH");
		_delay_ms(3000);
	}


}
