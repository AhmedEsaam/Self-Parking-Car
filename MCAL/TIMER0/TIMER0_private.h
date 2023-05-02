/*
 * TIMER0_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Abdelrahman Nasr
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_



#define CLOCK_SELECT_MASK           0b11111000




#define OC0_CLEAR_MASK              0b11001111



/****************************************** Timer 0 ********************************************/
#define TCNT0   (*(volatile u8*)0x52)
#define OCR0    (*(volatile u8*)0x5C)

#define TCCR0   (*(volatile u8*)0x53)
#define TCCR0_FOC0    7
#define TCCR0_WGM00   6
#define TCCR0_COM01   5
#define TCCR0_COM00   4
#define TCCR0_WGM01   3
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0
/***********************************************************************************************/

/*Timer 1*/


#define TCCR1A   (*(volatile u8*)0x4F)
#define TCCR1B   (*(volatile u8*)0x4E)
#define TCCR1   (*(volatile u16*)0x4E)


#define TCNT1H   (*(volatile u8*)0x4D)
#define TCNT1L   (*(volatile u8*)0x4C)
#define TCNT1   (*(volatile u16*)0x4C)


#define OCR1AH   (*(volatile u8*)0x4B)
#define OCR1AL   (*(volatile u8*)0x4A)
#define OCR1A   (*(volatile u16*)0x4A)


#define OCR1BH   (*(volatile u8*)0x49)
#define OCR1BL   (*(volatile u8*)0x48)
#define OCR1B   (*(volatile u16*)0x48)


#define ICR1H   (*(volatile u8*)0x47)
#define ICR1L   (*(volatile u8*)0x46)
#define ICR1   (*(volatile u16*)0x46)





/******************TCCR1A*********/
#define     TCCR1A_WGM10        0                               // WaveGeneration Mode Bit 0
#define     TCCR1A_WGM11        1                               // WaveGeneration Mode Bit 1
#define     TCCR1A_FOC1B        2                               // Force Output Compare 1 Channel B
#define     TCCR1A_FOC1A        3                               // Force Output Compare 1 Channel A
#define     TCCR1A_COM1B0       4                               // Compare Output Mode 1 Channel B Bit 0
#define     TCCR1A_COM1B1       5                               // Compare Output Mode 1 Channel B Bit 1
#define     TCCR1A_COM1A0       6                               // Compare Output Mode 1 Channel A Bit 0
#define     TCCR1A_COM1A1       7                               // Compare Output Mode 1 Channel A Bit 1


/******************TCCR1B*********/
#define     TCCR1B_CS10         0                               // Timer/Counter 1 Clock Selection Bit 0
#define     TCCR1B_CS11         1                               // Timer/Counter 1 Clock Selection Bit 1
#define     TCCR1B_CS12         2                               // Timer/Counter 1 Clock Selection Bit 2
#define     TCCR1B_WGM12        3                               // WaveGeneration Mode Bit 0
#define     TCCR1B_WGM13        4                               // WaveGeneration Mode Bit 1
#define     TCCR1A_ICES1        6                               // Timer/Counter 1 Input Capture Edge Selection
#define     TCCR1A_ICNC1        7                               // Timer/Counter 1 Input Capture Noise Cancellation
/*********/
#define TIMSK   (*(volatile unsigned char*)0x59)
#define TIMSK_OCIE2   7
#define TIMSK_TOIE2   6
#define TIMSK_TICIE1  5
#define TIMSK_OCIE1A  4
#define TIMSK_OCIE1B  3
#define TIMSK_TOIE1   2
#define TIMSK_OCIE0   1
#define TIMSK_TOIE0   0

#define TIFR    (*(volatile unsigned char*)0x58)
#define TIFR_OCF2    7
#define TIFR_TOV2    6
#define TIFR_ICF1    5
#define TIFR_OCF1A   4
#define TIFR_OCF1B   3
#define TIFR_TOV1    2
#define TIFR_OCF0    1
#define TIFR_TOV0    0


#define NULL (void*)0
void (*pvoid_TOV_NotificationFunc)(void) = NULL;
void (*pvoid_OCR_NotificationFunc)(void) = NULL;


#define WDTCR  *((volatile u8 *)0x41)
#define WDTCR_WDP0   0
#define WDTCR_WDP1   1
#define WDTCR_WDP2   2
#define WDTCR_WDE    3
#define WDTCR_WDTOE  4


#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
