/**
 * @file 	ULTRASONIC_int.c
 * @author 	Doaa Hagag (doaahagag128@gmail.com)
 * @brief 	Driver for ULTRASONIC sensor
 * @version 0.1
 * @date 2023-05-04
 * @copyright Copyright (c) 2023
 *
 */


/*
 * LIBRARY INCLUSION
*/
#include <avr/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
 * LOWER LIBRERY INCLUSION
*/

#include "../../MCAL/TIMER0/TIMER0_interface.h"
#include "../../MCAL/DIO/DIO_int.h"
/*
 * SELF FILES INCLUSION
*/
#include "ULTRASONIC_int.h"
#include "ULTRASONIC_priv.h"
#include "ULTRASONIC_config.h"


// TickTime= prescaler / F_CPU =  64 / 16 = 4
#define TickTime  4
#define Sound_Rate 34300 // cm/sec

u16 Global_u16Reading1 =0;
u16 Global_u16Reading2 =0;
u8 Global_u8StateCounter=0;


void ICU_HW (void);
void HULTRASONIC_voidInit(void)
{
	// set ICP1 pin as INPUT
	MDIO_voidSetPinDirection(PORTD_ID,PIN6_ID,INPUT);
	// set direction for trigg to be OUTPUT
	MDIO_voidSetPinDirection(PORTC_ID,PIN5_ID,OUPUT);

	// Initialize ICU
	ICU_voidInterruptControl(ICU_Enable);
	// Set Call Back
	ICU_voidSetCallback(ICU_HW);

	// Initialize Timer1
	Timer1_voidInit(); // timer1 start
}

void HULTRASONIC_voidReadDistance(u16 *Local_pu16Distance)
{
	u32 Local_u32PeridTicks =0 ;

	// Send Trigger
	// Send High
	MDIO_voidSetPinValue(PORTC_ID,PIN5_ID, HIGH );
	// Delay for 10 micro secs (ON period)
	_delay_us(10);
	// send Low
	MDIO_voidSetPinValue(PORTC_ID,PIN5_ID,LOW);

	// busy wait until counter =2
	while (Global_u8StateCounter != 2);
	Global_u8StateCounter =0 ;

	// Calculate PWM Parameters
	u32 PeriodTicks = Global_u16Reading2 - Global_u16Reading1 ;
	u32 Time = PeriodTicks * TickTime ; // In us
	u32 Distance =ceil ((((float)Time/2 )/ 1000000.0) * Sound_Rate)  ; // distance in cm
	*Local_pu16Distance = Distance ;
}

void ICU_HW (void)
{
	switch (Global_u8StateCounter)
	{
	case 0 :
		// read
		Global_u16Reading1 = ICU_u16getICRRegister();
		// change trigger to be falling
		ICU_voidSetTRiggerSignal(FALLING_EDGE);
		break;
	case 1 :
		// read
		Global_u16Reading2 = ICU_u16getICRRegister();
		// disable ICU Interrupt
		ICU_voidInterruptControl (ICU_Disable);
		break ;
	default : /* do nothing */
			break;
	}
	Global_u8StateCounter ++ ;
}
