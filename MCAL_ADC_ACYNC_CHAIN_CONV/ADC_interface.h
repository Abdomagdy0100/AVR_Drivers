/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_ADC_Peripheral            */
/******************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/***********************************************************************
 * Description: This struct for chain conversion            	     ***
 * Input 1 : at which channels?	>> array of channels - I choose them ***											***
 * Input 2 : store the out of these channels to array of results	 ***
 * Input 3 : the size of which									     ***
 ***********************************************************************/
typedef struct
{
	u8*  Channel;
	u16* Result;
	u8   size;
	void (*NotificationFunc)(void);
}chain_type;

/*--------------------------------------------------------------------*/

/******************************************************************
 * Description: This Function Initializes the ADC Peripheral	***
 * Input : 	void												***
 * Output:	void												***
 *****************************************************************/
void ADC_voidInit (void);

/*--------------------------------------------------------------------*/

/**************************************************************************
 * Input 1 : 	u8 , Range: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6	***
 * Input 2 :    address to store the reading value as pointer			***
 * Output  :	u16	the error state		     				 			***
 **************************************************************************/
u8  ADC_SYNC_StartConversion(u8 Copy_u8Channel, u8* ADC_u8_Reading);

/*--------------------------------------------------------------------*/

/**************************************************************************
 * Input 1 : 	u8 , Range: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6	***
 * Input 2 :    address to store the reading value as pointer			***
 * Input 3 :    call back notification function after finish conversion	***
 * Output  :	u16	the error state		     				 			***
 **************************************************************************/
u8  ADC_ASYNC_StartConversion(u8 Copy_u8Channel, u8* Copy_u8_Reading,void (*Copy_Pointer_CallBack_Notification_Func)(void));

/*--------------------------------------------------------------------*/

/**************************************************************************
 * Description: chain conversion of some conversions					***
 * Input 1 : 	your struct												***
 **************************************************************************/
u8  ADC_ASYNC_StartChainConversion(chain_type * copy_chain);

#endif /* ADC_INTERFACE_H_ */
