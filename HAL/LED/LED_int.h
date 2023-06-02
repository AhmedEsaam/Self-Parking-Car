/*
 * LED_int.h
 *
 *  Created on: Apr 1, 2023
 *      Author: doaah
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

/////////////////////////////////////
/// LINK TIME CONFIGURATION /////////
/////////////////////////////////////

typedef struct{
	u8 LED_PORT ;
	u8 LED_PIN ;
}LED_t ;


/**
 * CHOOSE LED_PORT FROM
 * PORTA_ID
 * PORTB_ID
 * PORTC_ID
 * PORTD_ID
 * */
/**
 * CHOOSE LED_PIN FROM
 * PIN0_ID
 * PIN1_ID
 * PIN3_ID
 * PIN4_ID
 * PIN5_ID
 * PIN6_ID
 * PIN7_ID
 * */


void HLED_voidLedInit(LED_t* LedOBJ);
void HLED_voidTurnOnLed(LED_t* LedOBJ);
void HLED_voidTurnOffLed(LED_t* LedOBJ);
void HLED_voidToggleLed(LED_t* LedOBJ);




#endif /* HAL_LED_LED_INT_H_ */
