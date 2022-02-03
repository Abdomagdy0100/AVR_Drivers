/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_DIO                       */
/******************************************************/

#include "LIB/types.h"
#include "LIB/util.h"

#include "DIO_int.h"
#include "DIO_priv.h"

/* IO Pins */
extern void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7))
	{
		if (u8PinValCopy == DIO_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: SET_BIT(DIO_u8PORTA_REG,u8PinIdCopy); break;
				case DIO_PORTB: SET_BIT(DIO_u8PORTB_REG,u8PinIdCopy); break;
				case DIO_PORTC: SET_BIT(DIO_u8PORTC_REG,u8PinIdCopy); break;
				case DIO_PORTD: SET_BIT(DIO_u8PORTD_REG,u8PinIdCopy); break;
			}

		}

		else if (u8PinValCopy == DIO_LOW)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: CLR_BIT(DIO_u8PORTA_REG,u8PinIdCopy); break;
				case DIO_PORTB: CLR_BIT(DIO_u8PORTB_REG,u8PinIdCopy); break;
				case DIO_PORTC: CLR_BIT(DIO_u8PORTC_REG,u8PinIdCopy); break;
				case DIO_PORTD: CLR_BIT(DIO_u8PORTD_REG,u8PinIdCopy); break;
			}
		}

		else
		{
			/* Do nothing, Wrong value to set */
		}
	}

	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

extern u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case DIO_PORTA: u8ResultLocal= GET_BIT(DIO_u8PINA_REG,u8PinIdCopy); break;
			case DIO_PORTB: u8ResultLocal= GET_BIT(DIO_u8PINB_REG,u8PinIdCopy); break;
			case DIO_PORTC: u8ResultLocal= GET_BIT(DIO_u8PINC_REG,u8PinIdCopy); break;
			case DIO_PORTD: u8ResultLocal= GET_BIT(DIO_u8PIND_REG,u8PinIdCopy); break;
		}
	}

	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}

	return u8ResultLocal;
}

extern void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7))
	{
		if ( u8PinDirCopy == DIO_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: SET_BIT(DIO_u8DDRA_REG,u8PinIdCopy); break;
				case DIO_PORTB: SET_BIT(DIO_u8DDRB_REG,u8PinIdCopy); break;
				case DIO_PORTC: SET_BIT(DIO_u8DDRC_REG,u8PinIdCopy); break;
				case DIO_PORTD: SET_BIT(DIO_u8DDRD_REG,u8PinIdCopy); break;
			}
		}

		else if ( u8PinDirCopy == DIO_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: CLR_BIT(DIO_u8DDRA_REG,u8PinIdCopy); break;
				case DIO_PORTB: CLR_BIT(DIO_u8DDRB_REG,u8PinIdCopy); break;
				case DIO_PORTC: CLR_BIT(DIO_u8DDRC_REG,u8PinIdCopy); break;
				case DIO_PORTD: CLR_BIT(DIO_u8DDRD_REG,u8PinIdCopy); break;
			}
		}

		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}

	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}


/* IO Ports */
extern void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case     DIO_PORTA: DIO_u8DDRA_REG = u8PortDir; break;
		case     DIO_PORTB: DIO_u8DDRB_REG = u8PortDir; break;
		case     DIO_PORTC: DIO_u8DDRC_REG = u8PortDir; break;
		case     DIO_PORTD: DIO_u8DDRD_REG = u8PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}

extern void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case     DIO_PORTA: DIO_u8PORTA_REG = u8PortVal; break;
		case     DIO_PORTB: DIO_u8PORTB_REG = u8PortVal; break;
		case     DIO_PORTC: DIO_u8PORTC_REG = u8PortVal; break;
		case     DIO_PORTD: DIO_u8PORTD_REG = u8PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}


