/*
 * INT_program.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "INT_interface.h"
#include "INT_private.h"
#include "INT_register.h"
#include "INT_config.h"


void ENT_ClearFlag(void)
{
	SET_BIT(GIFR,GIFR_INTF0);
	SET_BIT(GIFR,GIFR_INTF1);
	SET_BIT(GIFR,GIFR_INTF2);
}

void ENT_voidint0Init(void)
{
	//Set sense control for INT0 to falling edge//
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	//peripheral interrupt enable for INT0//
	SET_BIT(GCIR,GCIR_INT0);
}

void ENT_voidint1Init(void)
{
	//Set sense control for INT1 to falling edge//
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	//peripheral interrupt enable for INT0//
	SET_BIT(GCIR,GCIR_INT1);
}

void ENT_voidint2Init(void)
{
	//Set sense control for INT2 to falling edge//
	CLR_BIT(MCUCR,MCUCSR_INT2);

	//peripheral interrupt enable for INT0//
	SET_BIT(GCIR,GCIR_INT2);
}

