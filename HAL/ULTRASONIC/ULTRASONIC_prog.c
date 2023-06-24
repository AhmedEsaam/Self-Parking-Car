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
#include <math.h> 	//ceil function


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
 * LOWER LIBRERY INCLUSION
*/
#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GIE/GIE_int.h"

/*
 * SELF FILES INCLUSION
*/
#include "ULTRASONIC_int.h"
#include "ULTRASONIC_priv.h"
#include "ULTRASONIC_config.h"


// TickTime= prescaler / F_CPU =  64 / 16 = 4
//#define TickTime  4
//#define Sound_Rate 34300 // cm/sec

volatile u16 Global_u16Reading1 =0;
volatile u16 Global_u16Reading2 =0;
volatile u8 Global_u8StateCounter=0;


void ICU_HW (void);
void HULTRASONIC_voidInit(void)
{
	// set ICP1 Echo pin as INPUT
	MDIO_voidSetPinDirection(ECHO_PORT,ECHO_PIN,INPUT);
	// set direction for trigg to be OUTPUT
	MDIO_voidSetPinDirection(TRIG_PORT,TRIG_PIN,OUPUT);

	// Initialize ICU
	ICU_voidInterruptControl(ICU_ENABLE);
	
	// Set Call Back
	ICU_vodSetCallBack(&ICU_HW);

	/* Enable Global Interrupt */
    M_GIE_void_enable();

	// Initialize Timer1
	TIMER1_voidInit(); // timer1 start
}

void HULTRASONIC_voidReadDistance(u32 *Local_pu32Distance)
{
	u16 Local_u16OnTicks =0;
	Global_u8StateCounter = 0;


	// Initialize ICU
	ICU_voidInterruptControl(ICU_ENABLE);
	/* Set The Trigger to be Rising Edge */
    ICU_voidSetTriggerSignal(ICU_RISING_EDGE);	

	// Send Trigger
	// Send High
	MDIO_voidSetPinValue(TRIG_PORT,TRIG_PIN, HIGH);
	// Delay for 10 micro secs (ON period)
	_delay_us(10);
	// send Low
	MDIO_voidSetPinValue(TRIG_PORT,TRIG_PIN,LOW);

	// busy wait until counter =2
	while (Global_u8StateCounter != 2);

	// Calculate PWM Parameters
	// u32 PeriodTicks = Global_u16Reading2 - Global_u16Reading1 ;
	// u32 Time = PeriodTicks * TickTime ; // In us
	// u32 Distance =ceil ((((float)Time/2 )/ 1000000.0) * Sound_Rate)  ; // distance in cm
	
	/*
		Sound velocity =   343.00 m/s = 34300 cm/s
		distance = (Sound Vel. * Timer Value) / 2 
		= 17150 * Timer value
		we have selected an internal 8 MHz oscillator frequency for ATmega16, 
		with presale = 8 for timer frequency. 
		Then time to execute 1 instruction is 1 us.

		= 17150 x (TIMER value) x 10^-6 cm
		= (TIMER value)/58.30 cm
	*/
	Local_u16OnTicks = Global_u16Reading2 - Global_u16Reading1 -1;
	u32 Local_u32Distance = ceil(Local_u16OnTicks / 58.3) - 1;
	*Local_pu32Distance = Local_u32Distance;
}

void ICU_HW (void)
{
	switch (Global_u8StateCounter)
	{
	case 0:
		// read
		Global_u16Reading1 = ICU_u16GetICRRegister();
		// change trigger to be falling
		ICU_voidSetTriggerSignal(ICU_FALLING_EDGE);
		break;
	case 1:
		// read
		Global_u16Reading2 = ICU_u16GetICRRegister();
		// disable ICU Interrupt
		ICU_voidSetTriggerSignal(ICU_DISABLE);
		break ;
	default : /* do nothing */
			break;
	}

	Global_u8StateCounter++;
}
