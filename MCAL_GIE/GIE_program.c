/*
 * GIE_program.c
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voiddisable(void)
{
	CLR_BIT(SREG,SREG_I);
}

