#include<LIB/BIT_MATH.h>
#include<LIB/STD_TYPES.h>

#include "DIO_int.h"
//#include "DIO_priv.h"

void main(void)
{
	DIO_GetPinValue(0,0);
	DIO_SetPinValue(0,0,0);
	DIO_SetPortDirection(0,0);
	while(1)
	{

	}
}
