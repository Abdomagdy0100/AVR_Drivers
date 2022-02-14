/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_TIMER                     */
/******************************************************/
/*In this program toggle LED when achieve 4000 in compare match counts */
			//HARDWARE PWM
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>

void main (void)
{
	u8 Local_u8_counter;

	/*Make the Led on Port(B)__PIN(4)__Pin of [OC 0]*/
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);

	//initialize the timer peripheral
	TIMER0_void_init();

	while(1)
	{
		for(Local_u8_counter=0 ; Local_u8_counter<255 ;Local_u8_counter++)
		{
			/*put the value of local counter to the compare match value
			 * in each itrate that will change the led itensity according to this value */
			TIMER0_void_SetCompareMatchVal(Local_u8_counter);
			_delay_ms(10);
		}
	}
}
