/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_ADC_Peripheral            */
/******************************************************/

/*
 *
 * In this application we need to read output from potentiometer and the out would be
 * on the port C on LED'S
 *
 * */
#include "LIB/STD_TYPES.h"

#include "DIO_int.h"
#include "ADC_interface.h"
#include "GIE_interface.h"

//notification function prototype
void ADC_Notification_Fun();

//make global variable to read the value coming to port A from POTINTIOMETER
u8 APP_Get_ADC_READ;
void main (void)
{
	/*all pins we want them to read analog values are set to be inputs
	 * and other pins that are being used as output to make specific function
	 * ---all these done as  next
	 * assume A is input all pins
	 * and    C is output all pins */
	DIO_SetPortDirection(DIO_PORTA,DIO_INPUT);  //input
	DIO_SetPortDirection(DIO_PORTC,DIO_OUTPUT); //output

	//initialization of ADC
	ADC_voidInit();

	//enable global interrupt
	GIE_voidEnable();

	while(1)
	{
		ADC_ASYNC_StartConversion(0,&APP_Get_ADC_READ,&ADC_Notification_Fun);
	}
}

void ADC_Notification_Fun()
{
	DIO_SetPortValue(DIO_PORTC,APP_Get_ADC_READ);
}
