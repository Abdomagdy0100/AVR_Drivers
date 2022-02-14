/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_TIMER                     */
/******************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_void_init(void);

u8 TIMER0_u8_Set_CallBack(void (*Copy_pv_CallBackFunc)(void));   //pv == pointer to void

void TIMER0_void_SetCompareMatchVal(u8 Copy_u8_value);  //fast PWM

#endif /* TIMER_INTERFACE_H_ */
