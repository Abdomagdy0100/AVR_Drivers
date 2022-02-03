/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_TIMER                     */
/******************************************************/
/*In this program toggle LED when achieve 4000 in compare match counts */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"

void LED();

void main (void)
{
	/*Make the Led on Port(B)__PIN(4)__Pin of [OC 0]*/
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);

	//initialize the timer peripheral
	TIMER0_void_init();

	//pointing to my ISR(LED) to call back after achieve 4000
	TIMER0_u8_Set_CallBack(& LED);

	/*Enable global interrupt */
	GIE_voidEnable();

	while(1)
	{

	}
}

//ISR function including the action when achieve the compare match counts

void LED(void)
{
	static u16 Local_u16Counter = 0; //defined one time in all program life cycle
	static u8  Local_u8LED_State=0;  //defined one time in all program life cycle
	Local_u16Counter ++;
	if (Local_u16Counter == 4000)    // 4000 is compare match counts
	{
		/*for led state there 8 bits initially for 0 and here we make flip for first bit
		 * to change value of variable from 0 to 1 and reverse next time */
		TOG_BIT(Local_u8LED_State ,0);

		/*but the variable value which could be 0 or 1 on OC pin at port B*/
		DIO_SetPinValue(DIO_PORTB,DIO_PIN3,Local_u8LED_State); // Port(B)__PIN(4)__Pin of [OC 0]

		/*make the counter to initial value again*/
		Local_u16Counter = 0;
	}
}
