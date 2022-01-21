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

// initializing global variables
static u8* ADC_u8_Reading =NULL;
static void (*ADC_Pointer_CallBack_Notification_Func)(void)=NULL;

//this variable takes value told me that ADC is now Busy or not
//not to make new conversion while there is conversion happen
u8 ADC_BUSY_STATE= IDLE ;

void ADC_voidInit (void)
{
	      /*ADMUX_register */
	//AVCC as reference voltage
	SET_BIT(ADMUX,ADMUX_REFSO);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	//Activate left adjust to use 8 bits
	SET_BIT(ADMUX,ADMUX_ADLAR);

	//Set Pre scaler to divide by 128
	SET_BIT(ADCSRA,ADCSRA_ADPSO);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

	//Enable peripheral-should be last part to make enable while every thing is OK
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8  ADC_SYNC_StartConversion(u8 Copy_u8Channel, u8* ADC_u8_Reading)
{
	u32 Local_counter=0;
	u8 Local_ErrorState=ok;
	//if ADC not busy
	if (ADC_BUSY_STATE == IDLE)
	{
		//make the busy state told me that now i'm busy
		ADC_BUSY_STATE = BUSY;
		//clear the mux bits in ADMUX register
		ADMUX &=0b11100000;

		//set the required channel into mux bits
		ADMUX |= Copy_u8Channel;

		//start conversion
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*polling (busy waiting)until the conversion complete flag is set or
		 * the counter reaches the time out value set in register file
		 * */
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && (Local_counter != ADC_TIMEOUT))
		{
			Local_counter++;
		}
		if(Local_counter == ADC_TIMEOUT)
		{
			//loop was broken because the time out has reached
			Local_ErrorState=Nok;
		}
		else
		{
			//clear the conversion complete flag
			/*i will make the flag down by my self because i'm using polling
			 * but if we use interrupt it will be down by it self--no need for this step*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			//Return the reading (Left adjust using 8 bits )== Look at last part in register.h
			*ADC_u8_Reading=ADCH;
			//make the busy state Not busy back to be able to make new conversion
			ADC_BUSY_STATE = IDLE;
		}
	}
	else
	{
		Local_ErrorState = PLEASE_ADC_IS_BUSY;
	}
	return Local_ErrorState;
}

u8  ADC_ASYNC_StartConversion(u8 Copy_u8Channel, u8* Copy_u8_Reading,void (*Copy_Pointer_CallBack_Notification_Func)(void))
{
	u8 Local_ErrorState=ok;

	//if ADC not busy
	if (ADC_BUSY_STATE == IDLE)
	{
		if((Copy_u8_Reading == NULL) || (Copy_Pointer_CallBack_Notification_Func == NULL))
		{
			Local_ErrorState = NULL_POINTER;
		}

		else
		{
			//make the busy state told me that now i'm busy
			ADC_BUSY_STATE = BUSY;
			//initialize reading variable
			ADC_u8_Reading = Copy_u8_Reading;

			ADC_Pointer_CallBack_Notification_Func =Copy_Pointer_CallBack_Notification_Func;

			//clear the mux bits in ADMUX register
			ADMUX &=0b11100000;

			//set the required channel into mux bits
			ADMUX |= Copy_u8Channel;

			//start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			//ADC interrupt enable
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_ErrorState = PLEASE_ADC_IS_BUSY;
	}
	return Local_ErrorState;;
}

void __vect_16 (void)  __attribute__((signal));
void __vect_16 (void)
{
	/*read ADC result which saved in the address of global variable
	 * then put it into 8 bit ADCH register by dererencing it's pointer
	 * and equaling it,s value to register (ADCH)
	 * */
	*ADC_u8_Reading =ADCH;

	//make the busy state Not busy back to be able to make new conversion
	ADC_BUSY_STATE = IDLE;

	/*invoke the call back notification function told me the conversion has
	 * completed */
	ADC_Pointer_CallBack_Notification_Func();

	//disable ADC interrupt
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*Here no need to clear the flag because the interrupt down the flag automatically*/
}
