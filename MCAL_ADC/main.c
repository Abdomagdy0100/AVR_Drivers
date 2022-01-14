/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_ADC_Peripheral            */
/******************************************************/

#include "LIB/STD_TYPES.h"

#include "DIO_int.h"
#include "ADC_interface.h"
/*In this application we need to read output from potentiometer and the out would be
 * on the port C on LED'S
 * */
void main (void)
{
	u8 Get_ADC_READ; //make local variable to read the value coming to port A from POTINTIOMETER

	/*all pins we want them to read analog values are set to be inputs
	 * and other pins that are being used as output to make specific function
	 * ---all these done as  next
	 * assume A is input all pins
	 * and    C is output all pins */

	DIO_SetPortDirection(DIO_PORTA,DIO_INPUT);  //input

	DIO_SetPortDirection(DIO_PORTC,DIO_OUTPUT); //output

	while(1)
	{
		Get_ADC_READ=ADC_ChannelReading(0); //the POTINTIO out connected to PORT(A) _ PIN(0)
		/*now the stored value coming from potentiometer we want it on port(C) as digital
		 * value  */
		DIO_SetPortValue(DIO_PORTC,Get_ADC_READ);
	}

}
