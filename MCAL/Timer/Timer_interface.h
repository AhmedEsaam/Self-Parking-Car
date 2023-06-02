/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author			        Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * v2.0		    APR 12, 2023	Ahmed Essam El-Mogy		Add ICU APIs
 * ----------------------------------------------------------------------------------
 */
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

// Modes Of Operation
#define     Normal_MODE                         0
#define     PHASE_CORRECT_PWM_MODE              1
#define     CTC_MODE                            2
#define     FAST_PWM_MODE                       3

// Clock Selection
#define     CLK_SEL_BIT_MASK                    0b11111000

#define     TIMER_STOP                          0b00000000
#define     DIVISION_FACTOR_1                   0b00000001
#define     DIVISION_FACTOR_8                   0b00000010
#define     DIVISION_FACTOR_64                  0b00000011
#define     DIVISION_FACTOR_256                 0b00000100
#define     DIVISION_FACTOR_1024                0b00000101
#define     TIMER_EXTERNAL_T0_FALLING_EDGE      0b00000110
#define     TIMER_EXTERNAL_T0_RISING_EDGE       0b00000111

// ICU
#define     ICU_RISING_EDGE                     1
#define     ICU_FALLING_EDGE                    0

#define     ICU_ENABLE                          1
#define     ICU_DISABLE                         0


/* Timer 0 */
void TIMER0_voidInit(void);
void TIMER0_voidSetBusyWaitMS_OVFMode(u32 Copy_u32DelayMS);
void TIMER0_voidSetBusyWaitMS_CTCMode(u32 Copy_u32DelayMS);
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8Value);
void TIMER0_voidSetOVFCallback(void (*pvoidNotificationFunction(void)));
void TIMER0_voidSetCTCCallback(void (*pvoidNotificationFunction(void)));
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);
u8 TIMER0_u8GetCounterValue();
// set mode in run time

/* Timer 1 */
void TIMER1_voidInit(void);
void TIMER1_coidSetICR1Value(u16 Copy_u16ICRValue);
void TIMER1_coidSetOCR1AValue(u16 Copy_u16OCR1AValue);
void TIMER1_voidClearTCNT1(void);
// ICU
void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal);
void ICU_vodSetCallBack(void (*NotifiFunction) (void));
u16 ICU_u16GetICRRegister(void);
void ICU_voidInterruptControl(u8 Copy_u8InterruptEnable);

#endif /* TIMER_INTERFACE_H */