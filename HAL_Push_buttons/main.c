
#include <avr/io.h>
#include <avr/delay.h>
#include "math.h"
#define F_CPU 8000000UL


void main(void)
{

	/* Set PORTB as output */
	DDRB   = 0xff;

	/* Set PORTA as input */
	CLR_BIT(DDRA,0);

	/* Connect A0 to Pull up resistor */
	SET_BIT(PORTA,0);

	while(1)
	{

		/* Check if A0 is High, Flash LED String */
		/*the logic of pressing button is done with A0*/
		if(GET_BIT(PINA,0) == 0)
		{
			PORTB = 0x01;

		}

		else
		{
			PORTB = 0;
		}
		_delay_ms(100);

	}
}


