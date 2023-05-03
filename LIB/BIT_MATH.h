/*
 * BIT_MATH.h
 *
 *  Created on: MAR 28, 2023
 *      Author: Doaa Hagag
 *	   Version: 1.1
 *	  compiler: GNU GCC
 *
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*************** FUNCTION LIKE MACRO TO MANIPULATE WITH BIT *******************/
#define SET_BIT(reg,bit_num)	(reg |= 1 << (bit_num))// reg = reg | (1<< bit)
#define CLR_BIT(reg,bit_num)  	(reg &= ~(1<< bit_num))
#define TOG_BIT(reg,bit_num)  	(reg ^= 1 << (bit_num))
#define GET_BIT(reg,bit_num)  	((reg>>(bit_num))& 1 )

/*************** FUNCTION LIKE MACRO TO MANIPULATE WITH REGISTERS *******************/
#define SET_REG(reg, value)		(reg = value)
#define GET_REG(reg)			(reg)
#define CLR_REG(reg)			(reg = 0x00)



#endif /* BIT_MATH_H_ */
