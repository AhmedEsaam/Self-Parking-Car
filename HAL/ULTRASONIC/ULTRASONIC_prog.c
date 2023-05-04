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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
 * LOWER LIBRERY INCLUSION
*/
#include "../../MCAL/TIMER0/TIMER0_interface.h"

/*
 * SELF FILES INCLUSION
*/
#include "ULTRASONIC_int.h"
#include "ULTRASONIC_priv.h"
#include "ULTRASONIC_config.h"

void HULTRASONIC_voidInit(void)
{
	// set direction for trigg to be OUTPUT
	M_DIO_void_setPinDir(PORTC_ID,PIN5, OUTPUT);
	// set ICP1 pin as INPUT
	M_DIO_void_setPinDir(PORTD_ID,PIN6, INPUT);
	// ICU init
	M_TIMER1_ICU_void_init();
	// Call back
	M_TIMER1_ICU_void_setCallBack(ICU_HW);
	// Enable ICU int
	M_TIMER1_ICU_void_IntEnable();

	M_TIMER1_void_init(); // timer1 start
}
void HULTRASONIC_voidReadDistance(u16 *Local_pu16Distance)
{

}
