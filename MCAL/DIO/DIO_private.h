/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DIO_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Version      :	v1.1
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 22, 2023		Ahmed Essam El-Mogy		Adding PORTs Macros
 * ----------------------------------------------------------------------------------
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/************************************************************************/
/* DIO Registers                                                        */
/************************************************************************/

// PORTA registers
#define PORTA   (*((volatile u8*) 0x3B))
#define DDRA    (*((volatile u8*) 0x3A))
#define PINA    (*((volatile u8*) 0x39))

// PORTB registers
#define PORTB   (*((volatile u8*) 0x38))
#define DDRB    (*((volatile u8*) 0x37))
#define PINB    (*((volatile u8*) 0x36))

// PORTC registers
#define PORTC   (*((volatile u8*) 0x35))
#define DDRC    (*((volatile u8*) 0x34))
#define PINC    (*((volatile u8*) 0x33))

// PORTD registers
#define PORTD   (*((volatile u8*) 0x32))
#define DDRD    (*((volatile u8*) 0x31))
#define PIND    (*((volatile u8*) 0x30))


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
