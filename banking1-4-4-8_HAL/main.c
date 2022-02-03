/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 8000000UL


void main(void)
{
	//initialization
	DDRD |= 0xff;//make pin 0 in port A to be output
	int i;
	//loop
	while(1)
	{
		PORTD |= 0xff;
		_delay_ms(100);
		for(i=0;i<=3;i++)
		{
		PORTD &=~(1<<i);//clear pin 0
		_delay_ms(500);
		}

		for(i=7;i>=4;i--)
		{
		PORTD &=~(1<<i);//clear pin 0
		_delay_ms(500);
		}


	}
}


