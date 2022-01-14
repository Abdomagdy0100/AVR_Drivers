/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "avr/interrupt.h"
#include "GIE_interface.h"
#include "INT_interface.h"

void main (void)
{
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);


	ENT_voidint0Init();

	GIE_voidEnable();

	while(1)
	{

	}

}
//void __vector_1(void) __attribute__((signal));
//void __vector_1(void)
ISR(INT0_vect)
{
	u8 i;
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	for(i=0 ;i<=10 ;i++)
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		_delay_ms(200);
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
		_delay_ms(200);
	}

}
