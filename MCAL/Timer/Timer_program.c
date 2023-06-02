/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"

static void (*Timer_pvoidOVFNotificationFunction) (void) = NULL;
static void (*Timer_pvoidCTCNotificationFunction) (void) = NULL;
static void (*ICU_NotificationFunction) (void) = NULL;

void TIMER0_voidInit(void)
{
    /* Set Normal Mode */
    // CLR_BIT(TCCR0, TCCR0_WGM00);
    // CLR_BIT(TCCR0, TCCR0_WGM01);

    /* Set CTC Mode */
//    CLR_BIT(TCCR0, TCCR0_WGM00);
//    SET_BIT(TCCR0, TCCR0_WGM01);

    /* Set Fast PWM Mode */
     SET_BIT(TCCR0, TCCR0_WGM00);
     SET_BIT(TCCR0, TCCR0_WGM01);

    /* Set Compare Output -> Set on Top, Clear on Compare (Non-Inverted Mode) */
    CLR_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);

    /* Set Prescaler */
    TCCR0 &= CLK_SEL_BIT_MASK;
    TCCR0 |= TIMER_PRESCALER_VALUE;
}

void TIMER1_voidInit(void)
{
    /* Set Normal Mode */
     CLR_BIT(TCCR1A, TCCR1A_WGM10);
     CLR_BIT(TCCR1A, TCCR1A_WGM11);
     CLR_BIT(TCCR1B, TCCR1B_WGM12);
     CLR_BIT(TCCR1B, TCCR1B_WGM13);

    /* Set Timer 1 In Mode 14 Set PWM With To Value  = ICR1 */
//    CLR_BIT(TCCR1A, TCCR1A_WGM10);
//    SET_BIT(TCCR1A, TCCR1A_WGM11);
//    SET_BIT(TCCR1B, TCCR1B_WGM12);
//    SET_BIT(TCCR1B, TCCR1B_WGM13);

    /* Set Compare Output -> Set on Top, Clear on Compare (Non-Inverted Mode) */
    CLR_BIT(TCCR1A, TCCR1A_COM1A0);
    SET_BIT(TCCR1A, TCCR1A_COM1A1);

    /* Set Prescaler */
    TCCR1B &= CLK_SEL_BIT_MASK;
    TCCR1B |= DIVISION_FACTOR_8;
}
void TIMER0_voidSetBusyWaitMS_OVFMode(u32 Copy_u32DelayMS)
{
	TIMER0_voidSetPreloadValue(6);

    u32 Local_u32NumberOfOVF;
    u32 Local_u32Counter = 0;
    Local_u32NumberOfOVF = (Copy_u32DelayMS * 1000UL) / 256UL;

    while(Local_u32Counter < Local_u32NumberOfOVF)
    {
        while(!GET_BIT(TIFR, TIFR_TOV0));
        SET_BIT(TIFR, TIFR_TOV0);
        Local_u32Counter++;
		TIMER0_voidSetPreloadValue(6);
    }
}
void TIMER0_voidSetBusyWaitMS_CTCMode(u32 Copy_u32DelayMS)
{
    /* Set Prescaler */
    TCCR0 &= CLK_SEL_BIT_MASK;
    TCCR0 |= DIVISION_FACTOR_8;
    /* Clear The Timer Register (Reset The Timer Register) */
    TCNT0 = 0;
    /* Set The compare match value */
    TIMER0_voidSetCTCCompareMatchValue(250); // compare value

    u32 Local_u32NumberOfCTCFlag;
    u32 Local_u32Counter = 0;
    Local_u32NumberOfCTCFlag = (Copy_u32DelayMS * 1000UL) / 250UL;

    while(Local_u32Counter < Local_u32NumberOfCTCFlag)
    {
        while(!GET_BIT(TIFR, TIFR_OCF0));
        SET_BIT(TIFR, TIFR_OCF0);
        Local_u32Counter++;
    }
    /* Return to the precaler set by user */
}
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
    TCCR0 = Copy_u8Value;
    
}
void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}
void TIMER0_voidSetOVFCallback(void (*pvoidNotificationFunction(void)))
{
    Timer_pvoidOVFNotificationFunction = pvoidNotificationFunction;
}
void TIMER0_voidSetCTCCallback(void (*pvoidNotificationFunction(void)))
{
    Timer_pvoidCTCNotificationFunction = pvoidNotificationFunction;
}
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
    if(Copy_u8Mode == Normal_MODE)
    {
        SET_BIT(TIMSK, TIMSK_TOIE0);
    }
    else if(Copy_u8Mode == CTC_MODE)
    {
        SET_BIT(TIMSK, TIMSK_OCIE0);
    }
}
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
    if(Copy_u8Mode == Normal_MODE)
    {
        CLR_BIT(TIMSK, TIMSK_TOIE0);
    }
    else if(Copy_u8Mode == CTC_MODE)
    {
        CLR_BIT(TIMSK, TIMSK_OCIE0);
    }
}
u8 TIMER0_u8GetCounterValue()
{
    return TCNT0;
}
u8 TIMER1_u8GetCounterValue()
{
    return TCNT1;
}


void TIMER1_coidSetICR1Value(u16 Copy_u16ICRValue)
{
    ICR1 = Copy_u16ICRValue;
}
void TIMER1_coidSetOCR1AValue(u16 Copy_u16OCR1AValue)
{
    OCR1A = Copy_u16OCR1AValue;
}
void TIMER1_voidClearTCNT1(void)
{
    TCNT1 = 0;
}
void ICU_voidInterruptControl(u8 Copy_u8InterruptEnable)
{
    switch (Copy_u8InterruptEnable)
    {
    case ICU_ENABLE:
        /* Set The input capture Interrupt Enable Bit to Enable THe Interrupt */
        SET_BIT(TIMSK, TIMSK_TICIE1);
        break;

    case ICU_DISABLE:
        /* Clear The input capture Interrupt Disnable Bit to Disable THe Interrupt */
        CLR_BIT(TIMSK, TIMSK_TICIE1);
        break;
    
    default:
        break;
    }
}

u16 ICU_u16GetICRRegister(void)
{
    return ICR1;
}

void ICU_vodSetCallBack(void (*NotifiFunction) (void))
{
    ICU_NotificationFunction = NotifiFunction;
}

void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal)
{
    switch (Copy_u8TriggerSignal)
    {
    case ICU_RISING_EDGE:
        /* Set Input Capture Edge to be Rising Edge*/
        SET_BIT(TCCR1B, TCCR1B_ICES1);
        break;
    
    case ICU_FALLING_EDGE:
        /* Set Input Capture Edge to be Falling Edge*/
        CLR_BIT(TCCR1B, TCCR1B_ICES1);
        break;

    default:
        break;
    }
    
}

// CTC ISR
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
    if(Timer_pvoidCTCNotificationFunction != NULL)
    {
        Timer_pvoidCTCNotificationFunction();
    }
}

// OVF ISR
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
    if(Timer_pvoidOVFNotificationFunction != NULL)
    {
        Timer_pvoidOVFNotificationFunction();
    }
}


// ICU ISR
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
    if(ICU_NotificationFunction != NULL)
    {
        ICU_NotificationFunction();
    }
    else
    {
        /* Do Nothing */
    }
}

