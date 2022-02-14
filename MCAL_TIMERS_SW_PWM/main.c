/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_TIMER                     */
/******************************************************/
/*In this program toggle LED when achieve 4000 in compare match counts */
			//SOFTWARE PWM
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"

void PWM ();

void main (void)
{
	/*The initial state of our pin is high*/
	DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);

	/*Make the Led on Port(B)__PIN(4)__Pin of [OC 0]*/
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	//initialize the timer peripheral
	TIMER0_void_init();

	//callback PWM function
	TIMER0_u8_Set_CallBack(& PWM);

	/*Enable global interrupt */
	GIE_voidEnable();

	while(1)
	{

	}
}

//ISR function including the action (PWM) when achieve the compare match counts

void PWM (void)
{
	 /*****************************************************************************************************/
	 /* Constructing my PWM signal
	 * (EAMPLE 1)
	 * which start from 0  in high level [done in line 1 in main] after 5 msec's set to be low
	 * then after 20 msec's back to high state and reset my counter to start from 0 again
	 *
	 * (EAMPLE 2)
	 * change the counter values which are we check on them  to change the shape of my PWM signal
	 * not only that but control number of pins of micro controller that they generate PWM signal
	 */
	 /*****************************************************************************************************/
	static u8 Local_u8_Counter=0;

	Local_u8_Counter ++; //counter increment

	if (Local_u8_Counter == 5) //check for counter after 5ms ( we can change this value)
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
	}
	else if (Local_u8_Counter == 20) //check for counter after 20ms ( we can change this value)
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		Local_u8_Counter =0; //reset the counter
	}
}
