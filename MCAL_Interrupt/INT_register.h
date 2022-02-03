/*
 * INT_register.h
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */

#ifndef INT_REGISTER_H_
#define INT_REGISTER_H_

/*GENERAL INTERRUPT CONTROL REGISTER _ GCIR _*/
/*   7      6        5      4      3      2      1      0
 *-----------------------------------------------------------
 * INT1 |  INT0  | INT2  |##### |##### |##### |##### |##### |
 *-----------------------------------------------------------
 * */
#define GCIR 			*((volatile u8*)0x5B)
#define GCIR_INT1 		7
#define GCIR_INT0 		6
#define GCIR_INT2	 	5

/*GENERAL INTERRUPT FLAG REGISTER _ GCIR _*///READ ONLY
/*   7         6        5      4      3      2      1      0
 *--------------------------------------------------------------
 * INTF1 |  INTF0  | INTF2  |##### |##### |##### |##### |##### |
 *--------------------------------------------------------------
 * */
#define GIFR 			*((volatile u8*)0x5A)
#define GIFR_INTF2	 	5
#define GIFR_INTF0 		6
#define GIFR_INTF1 		7
//////////////////////////////////////////////////////////////////////////////////
/*MCUCR _ MCU CONTROL REGISTER _*/
/*   7         6        5        4      3      2      1      0
 *--------------------------------------------------------------
 * ###### | ####### |#######  |##### |ISC11 |ISC10 |ISC01 |ISC00|
 *--------------------------------------------------------------
 * */
#define MCUCR			*((volatile u8*)0x55)
#define MCUCR_ISC11 	3
#define MCUCR_ISC10 	2
#define MCUCR_ISC01 	1
#define MCUCR_ISC00 	0
//////////////////////////////////////////////////////////////////////////////////////
/*MCUCR _ MCU Control and Status Register _*/
/*   7      6     5       4      3       2       1        0
 *--------------------------------------------------------------
 * ###### |INT2 |######|##### |####### |##### |###### |######|
 *--------------------------------------------------------------
 * */
#define MCUCSR			*((volatile u8*)0x54)
#define MCUCSR_INT2 	6


#endif /* INT_REGISTER_H_ */
