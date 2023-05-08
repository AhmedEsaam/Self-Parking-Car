
/**
 * @file APP_Main.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief :
 * @version 1.0 main updated
 * @date 2023-05-04
 * @compiler GNU GCC
 * @copyright Copyright (c) 2023
 *
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include  <util/delay.h>
#include <math.h> 	//ceil function
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"


void main(void)
{
	u16 Distance ;
	// enable LCD
	HLCD_voidInit();
	// enable ULTRASONIC
	HULTRASONIC_voidInit();
	// enable GIE
	M_GIE_void_enable();
	while (1)
	{
		HULTRASONIC_voidReadDistance(&Distance);
		HLCD_voidSendNumber((u32)Distance);
		_delay_ms(1000);
		HLCD_voidClearDisplay();
		_delay_ms(1000);
		HLCD_voidSendNumber(50);
		_delay_ms(1000);
		HLCD_voidClearDisplay();
		_delay_ms(1000);
	}

}




#if 0

// TickTime= prescaler / F_CPU =  64 / 16 = 4
#define TickTime  4
#define Sound_Rate 34300 // cm/sec
u16 Global_u16Reading1 =0;
u16 Global_u16Reading2 =0;
u8 Global_u8StateCounter=0;
void ICU_HW (void);
void main(void)
{
	u32 Local_u32PeridTicks =0 ;
	// Initialize LCD
	HLCD_voidInit();
	// Enable GIE
	M_GIE_void_enable();
	// Initialize Timer1
	Timer1_voidInit();
	// Set Call Back
	ICU_voidSetCallback(ICU_HW);
	// Initialize ICU
	ICU_voidInterruptControl(ICU_Enable);
	// set ICP1 pin as INPUT
	MDIO_voidSetPinDirection(PORTD_ID,PIN6_ID,INPUT);
	// set direction for trigg to be OUTPUT
	MDIO_voidSetPinDirection(PORTC_ID,PIN5_ID,OUPUT);

	// Send Trigger
	MDIO_voidSetPinValue(PORTC_ID,PIN5_ID, HIGH );
	_delay_us(10);
	MDIO_voidSetPinValue(PORTC_ID,PIN5_ID,LOW);

	// busy wait until counter =2
	while (Global_u8StateCounter != 2);

	// Calculate PWM Parameters
	u32 PeriodTicks = Global_u16Reading2 - Global_u16Reading1 ;
	u32 Time = PeriodTicks * TickTime ; // In us
	u32 Distance =ceil (((Time/2 )/ 1000000.0) * Sound_Rate)  ; // distance in cm
	HLCD_voidSendNumber(Distance);
	//HLCD_voidSendNumber(30);
	while(1)
	{


	}

}
void ICU_HW (void)
{
	if (Global_u8StateCounter ==0 )
	{
		// read
		Global_u16Reading1 = ICU_u16getICRRegister();
		// change trigger to be falling
		ICU_voidSetTRiggerSignal(FALLING_EDGE);
	}
	else if (Global_u8StateCounter ==1 )
	{

		// read
		Global_u16Reading2 = ICU_u16getICRRegister();
		// disable ICU Interrupt
		ICU_voidInterruptControl (ICU_Disable);
	}
	Global_u8StateCounter ++ ;
}


#endif



#if 0
// Name animation
void main(void)
{
	HLCD_voidInit();
	while(1)
	{
		HLCD_voidGoToXY(1,0);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,0);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,4);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(1,4);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(1,8);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,8);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,12);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(1,12);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

	}
}
#endif
