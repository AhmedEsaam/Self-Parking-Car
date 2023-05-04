/**
 * @file DIO_priv.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief DIO Driver for ATMEGA32 
 * @version 0.1
 * @date 2023-03-25
 * @copyright Copyright (c) 2023
 */
#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_

/**
 * @brief  Adresses of registers DDRx, PORTx, PINx
 *          according to data sheet in Register Summary.
 */
#define PORTA   *((volatile u8*)0x3B)
#define DDRA   *((volatile u8*)0x3A)
#define PINA    *((volatile u8*)0x39)


#define PORTB   *((volatile u8*)0x38)
#define DDRB   *((volatile u8*)0x37)
#define PINB    *((volatile u8*)0x36)

#define PORTC   *((volatile u8*)0x35)
#define DDRC   *((volatile u8*)0x34)
#define PINC    *((volatile u8*)0x33)

#define PORTD   *((volatile u8*)0x32)
#define DDRD   *((volatile u8*)0x31)
#define PIND    *((volatile u8*)0x30)

#endif /* MCAL_DIO_DIO_PRIV_H_ */
