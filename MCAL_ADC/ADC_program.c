/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101			      */
/* Student ID : 012008210103			      */
/* Subject    : Interfacing_ADC_Peripheral            */
/******************************************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

void ADC_voidInit (void)
{
	      /*ADMUX_register */
	//AVCC as reference voltage
	SET_BIT(ADMUX,ADMUX_REFSO);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	//Activate left adjust to use 8 bits
	SET_BIT(ADMUX,ADMUX_ADLAR);

	//Set Prescaler to divide by 128
	SET_BIT(ADCSRA,ADCSRA_ADPSO);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

	//Enable peripheral-should be last part to make enable while every thing is OK
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8  ADC_ChannelReading(u8 Copy_u8Channel)
{
	//clear the mux bits in ADMUX register
	ADMUX &=0b11100000;

	//set the required channel into mux bits
	ADMUX |= Copy_u8Channel;

	//start conversion
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	//polling (busy waiting)until the conversion complete flag is set
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	//clear the conversion complete flag
	/*i will make the flag down by my self because i'm using polling
	 * but if we use interrupt it will be down by it self--no need for this step*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	//Return the reading (Left adjust using 8 bits )== Look at last part in register.h
	return ADCH;

}
