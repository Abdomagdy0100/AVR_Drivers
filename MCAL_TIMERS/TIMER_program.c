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

	/*Set the compare match value */
	OCR0 = 250;

	/*prescaler : Division by 8 */
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
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
	if(TIMER0_pv_CallBackFunc != NULL)
	{
		TIMER0_pv_CallBackFunc();
	}
}
