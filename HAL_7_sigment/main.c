#include <avr/delay.h>
#include "ssdconfig.h"
#include "LIB/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void main(void)
{
	//initialization
	DIO_SetPortDir(DIO_PORTD, DIO_PORT_OUTPUT);
	int i;
	int ssd[10]={zero,one,two,three,four,five,six,seven,eight,nine};

	//loop
	while(1)
	{

		for(i=0; i<10;i++)
		{
			//pins as output
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN0, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN2, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN6, DIO_OUTPUT);
			//DIO_vidSetPinDir(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);

			//draw the pattern on SSD by putting value on port is it
			DIO_SetPortVal(DIO_PORTD, ssd[i] );



			_delay_ms(500);
		}
	}
}


