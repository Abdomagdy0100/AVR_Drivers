/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101			      */
/* Student ID : 012008210103			      */
/* Subject    : Interfacing_DIO                       */
/******************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define PORTA_REG  *((volatile u8*) 0x3B)
#define PINA_REG   *((volatile u8*) 0x39)
#define DDRA_REG   *((volatile u8*) 0x3A)

#define PORTB_REG  *((volatile u8*) 0x38)
#define PINB_REG   *((volatile u8*) 0x36)
#define DDRB_REG   *((volatile u8*) 0x37)

#define PORTC_REG  *((volatile u8*) 0x35)
#define PINC_REG   *((volatile u8*) 0x33)
#define DDRC_REG   *((volatile u8*) 0x34)

#define PORTD_REG  *((volatile u8*) 0x32)
#define PIND_REG   *((volatile u8*) 0x30)
#define DDRD_REG   *((volatile u8*) 0x31)

//look at data sheet (reg summary)

/*why write volatile ?
 * because there part of compiler called "----" ,if found any variable not used it will change it's psition
 * to general perpose register so write volatile to stop tis action leave it as is it is
 *
 * >>coud be happened if there pin works as input compiler detect it not used but in real it change
 * it's state by external hardware ....
 * */




#endif /* DIO_PRIVATE_H_ */
