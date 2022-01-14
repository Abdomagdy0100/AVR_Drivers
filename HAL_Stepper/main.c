/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_Stepper_Motor             */
/******************************************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO_int.h"

void main(void)
{
	u8 Angel=25;
	u8 Angel_iterations;
	u8 Counter;
	u8 step=0.175; //each step is for 0.175 degrees

	//make pins going to ULN are output
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);

	//how many steps to achieve the needed Angel
	Angel_iterations=(Angel/step)/4; //as 4 is number of iterations for each step;


	while(1)
	{
		for(Counter=1  ; Counter<=Angel_iterations ; Counter++)
		{
			//for make full step we need 4 iterations
			//iterate (1)
			DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_HIGH);
			//iterate (2)
			DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_LOW);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_HIGH);
			//iterate (3)
			DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_LOW);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_HIGH);
			//iterate (4)
			DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_LOW);
		}

	}
}

