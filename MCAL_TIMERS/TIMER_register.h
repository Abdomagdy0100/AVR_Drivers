/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_TIMER                     */
/******************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define   	TCCR0    				*((volatile u8*)0x53) //timer0 control register
#define		TCCR0_WGM00				6 					  //wave form generation mode bit0
#define		TCCR0_WGM01				3					  //wave form generation mode bit1
#define 	TCCR0_CS02				2					  //prescaler bit2
#define 	TCCR0_CS01				1 					  //prescaler bit1
#define 	TCCR0_CS00				0 				      //prescaler bit0

#define 	OCR0   					*((volatile u8*)0x5c) //output compare register 0
#define 	TIMSK   				*((volatile u8*)0x59) //Timer mask

#define 	TIMSK_OCIE0      		1                     //Output compare 0 interrupt enable

#endif /* TIMER_REGISTER_H_ */
