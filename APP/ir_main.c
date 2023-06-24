/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ir_main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 15, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 15, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/ADC/ADC_interface.h"

#include "util/delay.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/IR/IR_interface.h"

static void intAction(void);
LED_t led1 = {PORTA_ID, PIN7_ID};
EXTI_t ext = {INT0, FALLING_EDGE};

void main(void)
{
	IR_t Local_IR1Sensor = {PORTD_ID, PIN2_ID};
	IR_voidInit(&Local_IR1Sensor);

	HLED_voidLedInit(&led1);
    M_GIE_void_enable();
    EXTI_voidInitPinConnection(&ext);
    EXTI_voidTriggerEdge(&ext);
    EXTI_voidEnable(&ext);
    HLED_voidTurnOffLed(&led1);
    EXTI_voidSetCallback(&ext, &intAction);

	while (1)
	{
	}
}

static void intAction(void)
{
    HLED_voidToggleLed(&led1);
}
