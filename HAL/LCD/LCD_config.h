/*
 * LCD_config.h
 *
 *  Created on: Mar 28, 2023
 *      Author: doaah
 */
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
/************************************************************/
/****************** Pre build configurations ****************/
/************************************************************/

/*Options:
    EIGHT_BIT_MODE
    FOUR_BIT_MODE
*/
#define LCD_INIT_MODE		EIGHT_BIT_MODE
/**
 * choose from
 *         PORTA_ID
 *         PORTB_ID
 *         PORTC_ID
 *         PORTD_ID
 * */
#define LCD_DATA_PORT		PORTA_ID
/**
 * choose from
 *         PORTA_ID
 *         PORTB_ID
 *         PORTC_ID
 *         PORTD_ID
 * */
#define LCD_CTRL_PORT		PORTB_ID
#define LCD_RS_PIN			PIN0_ID
#define LCD_RW_PIN			PIN1_ID
#define	LCD_EN_PIN			PIN2_ID


#endif // HAL_LCD_LCD_CONFIG_H_
