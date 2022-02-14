/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_TIMER                     */
/******************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pv_CallBackFunc)(void)= NULL; //make sure that pointer is points to NULL

void TIMER0_void_init(void)
{
	/*choosing  CTC mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Output compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Set the compare match value - Look at this part in PWM to know 125 from where*/
	OCR0 = 125;

	/*prescaler : Division by 64 */
	SET_BIT(TCCR0,TCCR0_CS00);   //1
	SET_BIT(TCCR0,TCCR0_CS01);   //1
	CLR_BIT(TCCR0,TCCR0_CS02);   //0
}


u8 TIMER0_u8_Set_CallBack(void (*Copy_pv_CallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=ok;

	if(Copy_pv_CallBackFunc != NULL)
	{
		  TIMER0_pv_CallBackFunc = Copy_pv_CallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vect_10 (void)  __attribute__((signal));
void __vect_10 (void)
{
	//we will write ISR in main file APP file inside callback function to be controllable

	if(TIMER0_pv_CallBackFunc != NULL)
	{
		TIMER0_pv_CallBackFunc();
	}
}
