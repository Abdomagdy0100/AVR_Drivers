/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
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

/*Creating global variables to take my locale ones to be visible for ISR*/
static u8*  ADC_pu8ChainChannelArr =NULL; 		//Global variable to carry chain array
static u8   ADC_u8ChainSize;					//Global variable to carry number of channels
static u16* ADC_pu16ChainResultArr =NULL;  		//Global variable to carry chain results from channels
static u8   ADC_u8ChainConversionIndex=0;		//Global variable to carry chain current conversion index

/*
 * Is the ISR come from single channel or from chain ?
 * Each has it's value and ISR function will check for it
 * */
static u8  ISR_Source;

//this variable takes value told me that ADC is now Busy or not
//not to make new conversion while there is conversion happen
u8 ADC_BUSY_STATE= IDLE ;
/*------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------*/

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
		Local_ErrorState = BUSY;
	}
	return Local_ErrorState;
}

/*------------------------------------------------------------------------------------------------------------*/

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

			//make ISR source is single channel asynchronous
			ISR_Source = Singel_Channel_Asynch;
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

/*------------------------------------------------------------------------------------------------------------*/

u8  ADC_ASYNC_StartChainConversion(chain_type * copy_chain)
{
	u8 Local_ErrorState=ok;
	//check the null pointer
	if(copy_chain==NULL)
	{
		Local_ErrorState = NULL_POINTER;
	}
	else
	{
		if(ADC_BUSY_STATE == IDLE)
		{
			//Make ADC busy
			ADC_BUSY_STATE = BUSY;
			//make ISR source is chain asynchronous
			ISR_Source = Chain_Asynch;
			//initialize chain channel array-but local into global to be visible for ISR
			ADC_pu8ChainChannelArr=copy_chain -> Channel;

			//initialize chain channels result array-but local into global to be visible for ISR
			ADC_pu16ChainResultArr=copy_chain -> Result;

			//initialize chain size -but local into global to be visible for ISR
			ADC_u8ChainSize=copy_chain -> size;

			//initialize notification function -but local into global to be visible for ISR
			ADC_Pointer_CallBack_Notification_Func=copy_chain -> NotificationFunc;

			//reinitialize current conversion index as (0) - confirmation only
			ADC_u8ChainConversionIndex=0;

			//set required channel through index (first channel >> ADC_u8ChainConversionIndex=0 )
			//first 5 bits all 0's
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			//start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);;

			//Enable conversion complete interrupt
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			Local_ErrorState = PLEASE_ADC_IS_BUSY;
		}
	}

	return Local_ErrorState;
}

/*------------------------------------------------------------------------------------------------------------*/


void __vect_16 (void)  __attribute__((signal));
void __vect_16 (void)
{
	if(ISR_Source == Singel_Channel_Asynch )
	{
		/****************************************************************/
		/*read ADC result which saved in the address of global variable
		 * then put it into 8 bit ADCH register by dererencing it's pointer
		 * and equaling it,s value to register (ADCH)*/
		/****************************************************************/
		*ADC_u8_Reading =ADCH;

		//make the busy state Not busy back to be able to make new conversion
		ADC_BUSY_STATE = IDLE;

		/*invoke the call back notification function told me the conversion has
		 * completed */
		ADC_Pointer_CallBack_Notification_Func();

		//disable ADC interrupt
		CLR_BIT(ADCSRA,ADCSRA_ADIE);

		/*****************************************************************************************/
		/* Here no need to clear the flag because the interrupt make the flag down automatically */
		/*****************************************************************************************/
	}

	else if(ISR_Source == Chain_Asynch )
	{
		/*Read the current conversion */
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex]=ADCH;

		/*Increment the index for next channel */
		ADC_u8ChainConversionIndex ++;

		/*Check is the chain finished or not */
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize)
		{
									//chain is finished
			/*ADC is now IDLE, ADC finished last conversion */
			ADC_BUSY_STATE = IDLE;

			/*Invoke the callback notification function */
			ADC_Pointer_CallBack_Notification_Func();

			/*Disable ADC conversion complete interrupt by my self because i'm opened it my self*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
								//chain is not finished
			/*Set new required channel*/
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			/*Start new conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}

}
