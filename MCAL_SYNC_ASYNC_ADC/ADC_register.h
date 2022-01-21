/******************************************************/
/* Author     : ABDO_MAGDY_AHMED                      */
/* Group ID   : 0120082101							  */
/* Student ID : 012008210103						  */
/* Subject    : Interfacing_ADC_Peripheral            */
/******************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define  	 ADMUX		     	     *((volatile u8*) 0x27)  //ADC multiplexer selection register
#define 	 ADMUX_REFS1 		  	 7  					 //Reference selection bitl
#define 	 ADMUX_REFSO  		   	 6						 //Reference selection bit0
#define  	 ADMUX_ADLAR    		 5						 //ADC left adjust result


#define 	 ADCSRA 				 *((volatile u8*) 0x26)	//ADC control and status register A
#define		 ADCSRA_ADEN			 7						//ADC enable
#define		 ADCSRA_ADSC			 6						//Start conversion
#define		 ADCSRA_ADATE 		     5 					    //Auto trigger enable
#define		 ADCSRA_ADIF			 4						//Interrupt flag
#define		 ADCSRA_ADIE			 3						//Interrupt enable
#define		 ADCSRA_ADPS2			 2						//Prescaler bit2
#define		 ADCSRA_ADPS1			 1						//Prescaler bitl
#define		 ADCSRA_ADPSO			 0						//Prescaler bit0

/******************************return type of ADC*******************************/
/********************************ADC_progranm.c*******************************/
//for Left adjust taking 8 bits that means to take only ADCH or ADCL
#define 	ADCH 					 *((volatile u8*) 0x25)	//ADC high register
#define		ADCL					 *((volatile u8*) 0x24)	//ADC Low register


//for right adjust taking 10 bits that means to take all ADCH & ADCL
#define		ADC						 *((volatile u16*) 0x24) //right adjust(10 bits)

#endif /* ADC_REGISTER_H_ */
