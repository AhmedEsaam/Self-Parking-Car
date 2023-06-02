/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EXTI_private.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 29, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 29, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Pins Connection On Hardware */
/* INT0 */
#define EXTI0_PORT      PORTD_ID
#define EXTI0_PIN       PIN2_ID
/* INT1 */
#define EXTI1_PORT      PORTD_ID
#define EXTI1_PIN       PIN3_ID
/* INT2 */
#define EXTI2_PORT      PORTB_ID
#define EXTI2_PIN       PIN2_ID

/* For Interrupt Senses */
#define MCUCR           *((volatile u8*) 0x55)
#define MCUCSR          *((volatile u8*) 0x54)

#define MCUCR_ISC00     0 
#define MCUCR_ISC01     1 
#define MCUCR_ISC10     2 
#define MCUCR_ISC11     3 

#define MCUCSR_ISC2     6

/* For Enabling External Interrupts (PIE) */
#define GICR            *((volatile u8*) 0x5B)

#define GICR_INT0       6
#define GICR_INT1       7
#define GICR_INT2       5

/* For External Interrupt Flag (PIF) */
#define GIFR            *((volatile u8*) 0x5A)

#define GIFR_INT0       6
#define GIFR_INT1       7
#define GIFR_INT2       5


#define INT0_INPUT_PULLUP                 0
#define INT0_INPUT_EXTERNALPULLDOWN       1
#define INT0_INPUT_EXTERNALPULLUP         2

#define INT1_INPUT_PULLUP                 0
#define INT1_INPUT_EXTERNALPULLDOWN       1
#define INT1_INPUT_EXTERNALPULLUP         2

#define INT2_INPUT_PULLUP                 0
#define INT2_INPUT_EXTERNALPULLDOWN       1
#define INT2_INPUT_EXTERNALPULLUP         2

#endif /* EXTI_PRIVATE_H */
