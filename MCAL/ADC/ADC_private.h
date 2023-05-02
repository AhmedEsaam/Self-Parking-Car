/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ADC_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 30, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 30, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef     ADC_PRIVATE_H
#define     ADC_PRIVATE_H

#define     RIGHT_ADJUST                0
#define     LEFT_ADJUST                 1

// Reference Voltage
#define     AREF                        0b00000000
#define     AVCC                        0b01000000
#define     INTERNAL_2v56               0b11000000

#define     REF_SEL_BIT_MASK            0b00111111


// Prescaler Selection
#define     DIVISION_FACTOR_2           0b00000001
#define     DIVISION_FACTOR_4           0b00000010
#define     DIVISION_FACTOR_8           0b00000011
#define     DIVISION_FACTOR_16          0b00000100
#define     DIVISION_FACTOR_32          0b00000101
#define     DIVISION_FACTOR_64          0b00000110
#define     DIVISION_FACTOR_128         0b00000111

#define     DIV_FACTOR_SEL_BIT_MASK     0b11111000


// Channel Selection Mask
#define     CHANNEL_SELECTION_MASK      0b11100000



#define     DISABLE                     0
#define     ENABLE                      1


/*-------------------------------- Register Description --------------------------------------*/

#define     ADMUX            *((volatile u8 *)0x27)  // ADC Multiplexer Selection Register
#define     ADMUX_MUX0       0                       // ADC Multiplexer Bit 0
#define     ADMUX_MUX1       1                       // ADC Multiplexer Bit 1
#define     ADMUX_MUX2       2                       // ADC Multiplexer Bit 2
#define     ADMUX_MUX3       3                       // ADC Multiplexer Bit 3
#define     ADMUX_MUX4       4                       // ADC Multiplexer Bit 4
#define     ADMUX_ADLAR      5                       // ADC Left Adjust Result
#define     ADMUX_REFS0      6                       // ADC Reference Selection Bit 0
#define     ADMUX_REFS1      7                       // ADC Reference Selection Bit 1

#define     ADCSRA           *((volatile u8 *)0x26)  // ADC Control and Status Register
#define     ADCSRA_ADPS0     0                       // ADC Prescaler Selection bit 0 
#define     ADCSRA_ADPS1     1                       // ADC Prescaler Selection bit 1
#define     ADCSRA_ADPS2     2                       // ADC Prescaler Selection bit 2
#define     ADCSRA_ADIE      3                       // ADC Interrupt Enable Bit
#define     ADCSRA_ADIF      4                       // ADC Interrupt Flag Bit
#define     ADCSRA_ADATE     5                       // ADC Auto Trigger Enable bit
#define     ADCSRA_ADSC      6                       // ADC Start Conversion bit
#define     ADCSRA_ADEN      7                       // ADC Enable Bit

#define     ADCH             *((volatile u8 *)0x25)  // ADC High Data Register  (8-bit)
#define     ADCL             *((volatile u8 *)0x24)  // ADC Low Data Register   (8-bit)
#define     ADC              *((volatile u16 *)0x24) // ADC Data Register       (16-bit)
 

#endif
