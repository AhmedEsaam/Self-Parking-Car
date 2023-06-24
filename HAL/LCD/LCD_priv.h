/*
 * LCD_priv.h
 *
 *  Created on: Mar 28, 2023
 *      Author: doaah
 */
#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/************************************************************/
/***************** Private macros ***************************/
/************************************************************/

#define 	EIGHT_BIT_MODE  1
#define 	FOUR_BIT_MODE   0
#define     LCD_ALL_OUTPUT  0xFF

#define FUNCTION_SET_CMD    0X38
#define DISPLAY_ON_OFF_CMD  0X0F
#define DISPLAY_CLEAR_CMD   0X01

/************************************************************/
/************Private Functions Prototypes********************/
/************************************************************/
static void HLCD_voidSendCommand (u8 Copy_u8Command);



#endif //  HAL_LCD_LCD_INT_H_
