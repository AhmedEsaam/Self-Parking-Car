/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ADC_interface.h
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

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_INTERRUPT_ENABLE      1
#define ADC_INTERRUPT_DISABLE     0

// Channel Options
#define     ADC_Channel_0                   0
#define     ADC_Channel_1                   1
#define     ADC_Channel_2                   2
#define     ADC_Channel_3                   3
#define     ADC_Channel_4                   4
#define     ADC_Channel_5                   5
#define     ADC_Channel_6                   6
#define     ADC_Channel_7                   7
//...

void ADC_voidInit(void);
void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);
void ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelNumber, void (*NotifiFunction)(void)); // Polling Mechanism (Asynchronous)
u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber); // Polling Mechanism (Synchronous or Blocking)

// ADC_init(void);
// ADC_SetChannel(Channel);
// ADC_InterruptControl(Interrupt_Status);
// u8 ADC_u8StartConversion(void);
// u16 ADC_u16StartConversion(void);
// u8 ADC_SetCallback(void);
// ISR


#endif
