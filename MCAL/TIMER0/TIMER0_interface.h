/*
 * TIMER0_interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Abdelrahman Nasr
 */


#ifndef MCAL_TIMER_INTERFACE_H_
#define MCAL_TIMER_INTERFACE_H_

#define TIMER0_NORMAL_MODE          0
#define TIMER0_FAST_MODE            1
#define TIMER0_CTC_MODE             2
#define TIMER0_PHASE_CORRECT_MODE   3

#define SCLAER_TIMER_STOP           0
#define SCLAER_1                    1
#define SCLAER_8                    2
#define SCLAER_64                   3
#define SCLAER_256                  4
#define SCLAER_1024                 5
#define EXTERNAL_FALLING_EDGE       6
#define EXTERNAL_RISING_EDGE        7


#define OCR0_DISCONECTED            0b00000000
#define OCR0_TOGGLE                 0b00010000
#define OCR0_CLEAR                  0b00100000
#define OCR0_SET                    0b00110000


#define RAISING_EDGE 1
#define FALLING_EDGE 0

#define ICU_Enable 1
#define ICU_Disable 0

void Timer0_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCRMode);
void Timer0_voidSetPreloadValue(u8 Copy_u8Value);
void Timer0_voidSetCompareMatchValue(u8 Copy_u8Value);

void Timer0_voidTOVSetCallBack(void (*Notification)(void));
void Timer0_voidOCMSetCallBack(void (*Notification)(void));

void Timer0_voidEnableInterrupt(u8 Copy_u8Mode);
void Timer0_voidDisableInterrupt(u8 Copy_u8Mode);

void Timer0_voidDelaySec(u16 Copy_u16Second);
void Timer0_voidDelayms(u16 Copy_u16MilliSec);
void Timer0_voidDelay_us(u32 Copy_u16MicroSec);

void timer1_Voidseticrvalue(u16 Copy_u16ICRValue);
void timer1_Voidsetocrvalue(u16 Copy_u16OCRValue);
void Timer1_voidInit(void);

void ICU_voidInterruptControl(u8 Copy_u8InterruptState);
void ICU_voidSetTRiggerSignal(u8 Copy_u8TriggerSignal);
void ICU_voidSetCallback(void (*Notification)(void));
u16 ICU_u16getICRRegister(void );


#define  WDT_SLEEP_16_3_MS 0b000
#define  WDT_SLEEP_32_5_MS 0b001
#define  WDT_SLEEP_64_8_MS 0b010

void WTD_voidEnable(void);

void WTD_voidDisable(void);
void WTD_voidSleep(u8 Copy_Timeout);



#endif /* TIMER0_INTERFACE_H_ */
