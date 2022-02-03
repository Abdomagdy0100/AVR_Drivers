/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101			      */
/* Student ID : 012008210103			      */
/* Subject    : Interfacing_DIO                       */
/******************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**********************Public macros ***************************/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_OUTPUT 1
#define DIO_INPUT 0

//port output states definitions for all port pins
#define DIO_PORT_HIGH	0xff
#define DIO_PORT_LOW	0x00

//port direction definitions for all port pins
#define DIO_PORT_OUTPUT	0xff
#define DIO_PORT_INPUT	0x00

/*************************************************************************/
/*this function for put value on specific pin in specific port
 * this function takes : port name (A,B,C,D) - pin number (0:7) - is it high or low */

void DIO_vidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal);


/*************************************************************************/
/*this function for assign direction of specific pin in specific port
 * this function takes : port name (A,B,C,D) - pin number (0:7) - is it output or input */

void DIO_vidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir);


/*************************************************************************/
/*this function for detect the input on specific pin in specific port
 * this function takes : port name (A,B,C,D) - pin number (0:7) */

u8 DIO_GetPinVal(u8 u8PortId, u8 u8PinId);


/*************************************************************************/
/*this function for put value on all port pins of port
 * this function takes : port name (A,B,C,D) - is it high or low */

void DIO_SetPortVal(u8 u8PortId, u8 u8PortVal);


/*************************************************************************/
/*this function for put value on all port pins of port
 * this function takes : port name (A,B,C,D) - is it output or input */

void DIO_SetPortDir(u8 u8PortId, u8 u8PortDir);

#endif /* DIO_INTERFACE_H_ */
