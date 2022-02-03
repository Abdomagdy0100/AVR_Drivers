/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101			      */
/* Student ID : 012008210103			      */
/* Subject    : Interfacing_DIO                       */
/******************************************************//
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"


void DIO_vidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		if(u8PinVal == DIO_HIGH)
		{
			switch(u8PortId)
			{
			case DIO_PORTA: SET_BIT(PORTA_REG,u8PinId);break;
			case DIO_PORTB: SET_BIT(PORTB_REG,u8PinId);break;
			case DIO_PORTC: SET_BIT(PORTC_REG,u8PinId);break;
			case DIO_PORTD: SET_BIT(PORTD_REG,u8PinId);break;

			}
		}

		else if(u8PinVal == DIO_LOW)
		{
			switch(u8PortId)
			{
			case DIO_PORTA: SET_BIT(PORTA_REG,u8PinId);break;
			case DIO_PORTB: CLR_BIT(PORTB_REG,u8PinId);break;
			case DIO_PORTC: CLR_BIT(PORTC_REG,u8PinId);break;
			case DIO_PORTD: CLR_BIT(PORTD_REG,u8PinId);break;
			}
		}
	}
}

void DIO_vidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
		{
			if(u8PinDir == DIO_OUTPUT)
			{
				switch(u8PortId)
				{
				case DIO_PORTA: SET_BIT(DDRA_REG,u8PinId);break;
				case DIO_PORTB: SET_BIT(DDRB_REG,u8PinId);break;
				case DIO_PORTC: SET_BIT(DDRC_REG,u8PinId);break;
				case DIO_PORTD: SET_BIT(DDRD_REG,u8PinId);break;

				}
			}

			else if(u8PinDir == DIO_INPUT)
			{
				switch(u8PortId)
				{
				case DIO_PORTA: SET_BIT(DDRA_REG,u8PinId);break;
				case DIO_PORTB: CLR_BIT(DDRB_REG,u8PinId);break;
				case DIO_PORTC: CLR_BIT(DDRC_REG,u8PinId);break;
				case DIO_PORTD: CLR_BIT(DDRD_REG,u8PinId);break;
				}
			}
		}
}

void DIO_SetPortVal(u8 u8PortId, u8 u8PortVal)
{
	if(u8PortId <= DIO_PORTD)
	{
		switch(u8PortId)
		{
		case DIO_PORTA: PORTA_REG=u8PortVal;break;
		case DIO_PORTB: PORTB_REG=u8PortVal;break;
		case DIO_PORTC: PORTC_REG=u8PortVal;break;
		case DIO_PORTD: PORTD_REG=u8PortVal;break;
		}

	}
}

void DIO_SetPortDir(u8 u8PortId, u8 u8PortDir)
{
	if(u8PortId <= DIO_PORTD)
		{
			switch(u8PortId)
			{
			case DIO_PORTA: PORTA_REG=u8PortDir;break;
			case DIO_PORTB: PORTB_REG=u8PortDir;break;
			case DIO_PORTC: PORTC_REG=u8PortDir;break;
			case DIO_PORTD: PORTD_REG=u8PortDir;break;
			}
		}
}

u8 DIO_GetPinVal(u8 u8PortId, u8 u8PinId)
{
	u8 u8Resultloc =0xff;
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA: u8Resultloc=GET_BIT(PINA_REG, u8PinId) ;break;
		case DIO_PORTB: u8Resultloc=GET_BIT(PINB_REG, u8PinId) ;break;
		case DIO_PORTC: u8Resultloc=GET_BIT(PINC_REG, u8PinId) ;break;
		case DIO_PORTD: u8Resultloc=GET_BIT(PIND_REG, u8PinId) ;break;
		}

	}
	return u8Resultloc;
}


