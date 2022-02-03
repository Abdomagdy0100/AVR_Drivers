/*
 * math.h
 *
 *  Created on: ???/???/????
 *      Author: magdy
 */

#ifndef MATH_H_
#define MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif /* MATH_H_ */
