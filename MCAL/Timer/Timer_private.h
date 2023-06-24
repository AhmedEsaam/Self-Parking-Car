/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author		    	    Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * v1.1		    APR 10, 2023	Ahmed Essam El-Mogy		Adding Timer1 Registers
 * v1.2		    APR 11, 2023	Ahmed Essam El-Mogy		Adding ICU Register and Bits
 * ----------------------------------------------------------------------------------
 */

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/*------------------------------------- Timers General Registers --------------------------------------*/

#define TIMSK               (*((volatile u8*) 0x59))      // Timer/Counter Interrupt Mask Register (Interrupt Enable)
#define TIMSK_TOIE0         0
#define TIMSK_OCIE0         1

#define TIMSK_TOIE1         2                             // Timer/Counter1, Overflow Interrupt Enable
#define TIMSK_OCIE1B        3                             // Timer/Counter1, Output Compare B Match Interrupt Enable
#define TIMSK_OCIE1A        4                             // Timer/Counter1, Output Compare A Match Interrupt Enable
#define TIMSK_TICIE1        5                             // Timer/Counter1, Input Capture Interrupt Enable

#define TIMSK_TOIE2         6
#define TIMSK_OCIE2         7


#define TIFR                (*((volatile u8*) 0x58))      // Timer/Counter Interrupt Flag Register
#define TIFR_TOV0           0
#define TIFR_OCF0           1

#define TIFR_TOV1           2                             // Timer/Counter1, Overflow Flag
#define TIFR_OCF1B          3                             // Timer/Counter1, Output Compare B Match Flag
#define TIFR_OCF1A          4                             // Timer/Counter1, Output Compare A Match Flag
#define TIFR_ICF1           5                             // Timer/Counter1, Input Capture Flag

#define TIFR_TOV2           6
#define TIFR_OCF2           7


/*------------------------------------------ Timer0 Registers ------------------------------------------*/

#define TCCR0               (*((volatile u8*) 0x53))      // Timer/Counter Control Register
// Clock Select Bit 
#define TCCR0_CS00          0
#define TCCR0_CS01          1
#define TCCR0_CS02          2
// Timer Mode
#define TCCR0_WGM00         6
#define TCCR0_WGM01         3
// Compare Output Mode
#define TCCR0_COM00         4
#define TCCR0_COM01         5

#define TCNT0               (*((volatile u8*) 0x52))      // Timer/Counter Register
#define OCR0                (*((volatile u8*) 0x5C))      // Output Compare Register


/*------------------------------------------ Timer1 Registers ------------------------------------------*/

#define TCCR1A               (*((volatile u8*) 0x4F))     // Timer/Counter1 Control Register A
// Clock Select Bit 
#define TCCR1A_WGM10         0                            // WaveGeneration Mode Bit 0                            
#define TCCR1A_WGM11         1                            // WaveGeneration Mode Bit 1
#define TCCR1A_FOC1B         2                            // Force Output Compare 1 Channel B
#define TCCR1A_FOC1A         3                            // Force Output Compare 1 Channel A
#define TCCR1A_COM1B0        4                            // Compare Output Mode 1 Channel B Bit 0
#define TCCR1A_COM1B1        5                            // Compare Output Mode 1 Channel B Bit 1
#define TCCR1A_COM1A0        6                            // Compare Output Mode 1 Channel A Bit 0
#define TCCR1A_COM1A1        7                            // Compare Output Mode 1 Channel A Bit 1

#define TCCR1B               (*((volatile u8*) 0x4E))     // Timer/Counter1 Control Register B
#define TCCR1B_CS10          0                            // Timer/Counter 1 Clock Selection Bit 0
#define TCCR1B_CS11          1                            // Timer/Counter 1 Clock Selection Bit 1
#define TCCR1B_CS12          2                            // Timer/Counter 1 Clock Selection Bit 2
#define TCCR1B_WGM12         3                            // WaveGeneration Mode Bit 0
#define TCCR1B_WGM13         4                            // WaveGeneration Mode Bit 1
#define TCCR1B_ICES1         6                            // Timer/Counter 1 Input Capture Edge Selection
#define TCCR1B_ICNC1         7                            // Timer/Counter 1 Input Capture Noise Cancellation

#define TCNT1                (*((volatile u16*) 0x4C))    // Timer/Counter1 – Counter Register
#define OCR1A                (*((volatile u16*) 0x4A))    // Timer/Counter1 – Output Compare Register A
#define OCR1B                (*((volatile u16*) 0x48))    // Timer/Counter1 – Output Compare Register B 
#define ICR1                 (*((volatile u16*) 0x46))    // Timer/Counter1 – Input Capture Register 


#endif /* TIMER_PRIVATE_H */