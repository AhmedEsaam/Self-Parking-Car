/*
 * TIMER0_prog.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Abdelrahman Nasr
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"



u8 Timer0_Scaler;
u8 Timer0_Mode;
u8 CPU_Clock;



void Timer1_voidInit(void)
{

	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);

	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

	SET_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);


}


void timer1_Voidseticrvalue(u16 Copy_u16ICRValue)
{
	ICR1= Copy_u16ICRValue;
}

void timer1_Voidsetocrvalue(u16 Copy_u16OCRValue)
{
	OCR1A= Copy_u16OCRValue;

}


void Timer0_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCRMode)
{
	/*Set Timer0 Mode*/
	switch (Copy_u8Mode)
	{
	case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		Timer0_Mode = TIMER0_NORMAL_MODE;
		break;
	case TIMER0_PHASE_CORRECT_MODE:
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		Timer0_Mode = TIMER0_PHASE_CORRECT_MODE;
		break;
	case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		Timer0_Mode = TIMER0_CTC_MODE;
		break;
	case TIMER0_FAST_MODE:
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		Timer0_Mode = TIMER0_FAST_MODE;

		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);

		break;

	default:
		break;
	}


	/*Set Timer0 Prescaler*/
	TCCR0 &= CLOCK_SELECT_MASK;
	TCCR0 |= Copy_u8Scaler;
	Timer0_Scaler = Copy_u8Scaler;

	/*Set OCR Mode*/
	TCCR0 &= OC0_CLEAR_MASK;
	TCCR0 |= Copy_u8OCRMode;


	//CPU_Clock = CPU_CLOCK;


}

void Timer0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

void Timer0_voidSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}


void Timer0_voidTOVSetCallBack(void (*Notification)(void))
{
	pvoid_TOV_NotificationFunc = Notification;
}

void Timer0_voidOCMSetCallBack(void (*Notification)(void))
{
	pvoid_OCR_NotificationFunc = Notification;
}

void Timer0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
	case TIMER0_NORMAL_MODE:
		SET_BIT(TIMSK, TIMSK_TOIE0);
		break;
	case TIMER0_FAST_MODE:
	case TIMER0_CTC_MODE:
	case TIMER0_PHASE_CORRECT_MODE:
		SET_BIT(TIMSK, TIMSK_OCIE0);
		break;

	default:
		break;
	}
}

void Timer0_voidDisableInterrupt(u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
	case TIMER0_NORMAL_MODE:
		CLR_BIT(TIMSK, TIMSK_TOIE0);
		break;
	case TIMER0_FAST_MODE:
	case TIMER0_CTC_MODE:
	case TIMER0_PHASE_CORRECT_MODE:
		CLR_BIT(TIMSK, TIMSK_OCIE0);
		break;

	default:
		break;
	}
}

void Timer0_voidDelaySec(u16 Copy_u16Second)
{

}

void Timer0_voidDelayms(u16 Copy_u16MilliSec)
{


	f32 Local_f32OVCounts = ((f32)Copy_u16MilliSec * 1000.0)/ 256.0;
	u32 Local_u32Counts = (u32)Local_f32OVCounts;
	u32 Local_u32Remender = Local_f32OVCounts - (u32)Local_f32OVCounts;
	u8 Local_u8PreloadValue = 0;

	if(Local_u32Remender != 0)
	{
		Local_u8PreloadValue = 256 * (1 - Local_u32Remender);
		Local_u32Counts += 1;
	}


	Timer0_voidSetPreloadValue(Local_u8PreloadValue);

	while(Local_u32Counts--)
	{
		while(GET_BIT(TIFR, TIFR_TOV0) == 0);
		SET_BIT(TIFR, TIFR_TOV0);
	}
}

void Timer0_voidDelay_us(u32 Copy_u16MicroSec)
{
	f32 Local_f32OVCounts = (f32)Copy_u16MicroSec/ 256.0;
	u16 Local_u16Counts = (u8) Local_f32OVCounts;
	u32 Local_u32Remender = Local_f32OVCounts - (s32)Local_f32OVCounts;
	u8 Local_u8PreloadValue = 0;

	if(Local_u32Remender != 0)
	{
		Local_u8PreloadValue = 256 * (1 - Local_u32Remender);
		Local_u16Counts += 1;
	}


	Timer0_voidSetPreloadValue(Local_u8PreloadValue);

	while(Local_u16Counts--)
	{
		while(GET_BIT(TIFR, TIFR_TOV0) == 0);
		SET_BIT(TIFR, TIFR_TOV0);
	}

}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(pvoid_TOV_NotificationFunc)
	{
		pvoid_TOV_NotificationFunc();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(pvoid_OCR_NotificationFunc)
	{
		pvoid_OCR_NotificationFunc();
	}
}

void ICU_voidSetTRiggerSignal(u8 Copy_u8TriggerSignal){

	switch (Copy_u8TriggerSignal)

	{
	case RAISING_EDGE:
		SET_BIT(TCCR1B,TCCR1A_ICES1);
		break;
	case FALLING_EDGE:
		CLR_BIT(TCCR1B,TCCR1A_ICES1);
		break;
	}
}
static void (*ICU_NotificationFunction)(void )=NULL;
u16 ICU_u16getICRRegister(void )
{
	return ICR1;

}

void ICU_voidInterruptControl(u8 Copy_u8InterruptState){
	switch (Copy_u8InterruptState)

	{
	case ICU_Enable:
		SET_BIT(TIMSK,TIMSK_TICIE1);
		break;
	case ICU_Disable:
		CLR_BIT(TIMSK,TIMSK_TICIE1);
		break;

	}



	}

void ICU_voidSetCallback(void (*Notification)(void))
{
	ICU_NotificationFunction = Notification;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
	{
		if(ICU_NotificationFunction)
		{
			ICU_NotificationFunction();
		}
	}


void WTD_voidEnable(void)
{
	SET_BIT( WDTCR,WDTCR_WDE);
}

void WTD_voidDisable(void)
{
	WDTCR= (1<<WDTCR_WDTOE) | (1 << WDTCR_WDE);
	WDTCR =0;
}


void WTD_voidSleep(u8 Copy_Timeout)
{
	WDTCR &= 0b1111000;
	WDTCR|= Copy_Timeout;
}
