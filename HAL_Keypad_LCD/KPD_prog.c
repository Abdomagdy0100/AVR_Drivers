/*
 * prog.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include "LIB/STD_TYPES.h"
#include<util/delay.h>
#include"DIO_int.h"
#include"DIO_priv.h"
#include"KPD_config.h"
#include"KPD_interface.h"
#include"KPD_private.h"

//using 2 dimensional array -- draw the pattern of key pad you want
u8 KPD_Arr [4][4]=
{
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','*'},
	{'c','0','=','/'},
};

u8  KPD_U8_GetKeyPressed(void)
{
	u8 col,row,sw_val = NotPressd;
	for(col=0;col<4;col++)
	{
		DIO_SetPinValue(DIO_PORTC,col,DIO_LOW);

		for(row=4;row<8;row++)
		{
			if(DIO_GetPinValue(DIO_PORTC,row)==0)
			{
				sw_val=KPD_Arr[row-4][col];
				while(DIO_GetPinValue(DIO_PORTC,row)==0);
				_delay_ms(50);
			}

		}

		DIO_SetPinValue(DIO_PORTC,col,DIO_HIGH);
	}

	return sw_val;
}
