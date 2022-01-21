/*
 * ADC_interface.h
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_ADC_Peripheral            */
/******************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/******************************************************************
 * Description: This Function Initializes the ADC Peripheral	***
 * Input : 	void												***
 * Output:	void												***
 *****************************************************************/
void ADC_voidInit (void);
/*--------------------------------------------------------------------*/
/**************************************************************************
 * Description: This Function Reads the Data Registers of The ADC		***
 * Input 1 : 	u8 , Range: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6	***
 * Input 2 :    address to store the reading value as pointer			***
 * Output  :	u16	the error state		     				 			***
 **************************************************************************/
u8  ADC_SYNC_StartConversion(u8 Copy_u8Channel, u8* ADC_u8_Reading);

#endif /* ADC_INTERFACE_H_ */
