/*
 * LED_prog.c
 *
 *  Created on: Apr 1, 2023
 *      Author: doaah
 */

/*
 * LIBRARY INCLUSION
*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
 * LOWER LIBRERY INCLUSION
*/
#include "../../MCAL/DIO/DIO_interface.h"

/*
 * SELF FILES INCLUSION
*/
#include "LED_int.h"
#include "LED_priv.h"
#include "LED_config.h"

/*****************************************************************
 ***********FUNCTION IMPLEMENTATION*******************************
 ***************************************************************/

void HLED_voidLedInit(LED_t* LedOBJ)
{
	MDIO_voidSetPinDir(LedOBJ->LED_PORT , LedOBJ->LED_PIN , OUTPUT);
}
void HLED_voidTurnOnLed(LED_t* LedOBJ)
{
	MDIO_voidSetPinValue (LedOBJ->LED_PORT  , LedOBJ->LED_PIN , HIGH);
}
void HLED_voidTurnOffLed(LED_t * LedOBJ)
{
	MDIO_voidSetPinValue (LedOBJ->LED_PORT  , LedOBJ->LED_PIN , LOW);
}
void HLED_voidToggleLed(LED_t* LedOBJ)
{
	MDIO_voidTogglePin(LedOBJ->LED_PORT , LedOBJ->LED_PIN );
}


