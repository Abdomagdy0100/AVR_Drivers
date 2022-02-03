/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void main(void)
{
	//initialization
	DDRB |= 0x01;//make pin 0 in port A to be output

	//loop
	while(1)
	{
		PORTB |=0x01;
		_delay_ms(100);
		PORTB &=~(1<<0);//clear pin 0
		_delay_ms(100);

	}

}


