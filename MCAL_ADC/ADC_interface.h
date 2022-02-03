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
/**********************************************************************
 * Description: This Function Reads the Data Registers of The ADC	***
 * Input : 	u8 , Range: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6	***
 * Output:	u16														***
 **********************************************************************/
u8  ADC_ChannelReading(u8 Copy_u8Channel) ;

#endif /* ADC_INTERFACE_H_ */
