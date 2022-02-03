/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101			      */
/* Student ID : 012008210103			      */
/* Subject    : Interfacing_DIO                       */
/******************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_


/***************************************************************************/
/***********************Public Definitions**********************************/
/***************************************************************************/

/* Port Defines */
#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

/* PIN Defines */
#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2    		2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7

/* Digital I/O value */
#define DIO_HIGH			1
#define DIO_LOW				0

/* Digital I/O Direction */
#define DIO_INPUT			0x00
#define DIO_OUTPUT			0xFF

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/*************************************FUNCTIONS******************************************/

/*this function for put value on specific pin in specific port
 * this function takes : port name (A,B,C,D) - pin number (0:7) - is it high or low */
extern void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

/****************************************************************************************/
/*this function for detect the input on specific pin in specific port
 * this function takes : port name (A,B,C,D) - pin number (0:7) */
extern u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);


/*************************************************************************/
/*this function for assign direction of specific pin in specific port
 * this function takes : port name (A,B,C,D) - pin number (0:7) - is it output or input */
extern void DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/*************************************************************************/
/*this function for put value on all port pins of port
 * this function takes : port name (A,B,C,D) - is it output or input */
extern void DIO_SetPortDirection(u8 u8PortId, u8 u8PortDir);

/*************************************************************************/
/*this function for put value on all port pins of port
 * this function takes : port name (A,B,C,D) - is it high or low */
extern void DIO_SetPortValue(u8 u8PortId, u8 u8PortVal);

#endif /* DIO_INT_H_ */
