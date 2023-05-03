/*
 * LCD_int.h
 *
 *  Created on: Mar 28, 2023
 *      Author: doaah
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

void HLCD_voidInit(void);
void HLCD_voidSendData (u8  copy_u8Data);
void HLCD_voidClearDisplay(void);
void HLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
void HLCD_voidSendString (u8 *Copy_pu8StringArray);
void HLCD_voidSendNumber (u32 Copy_u32Number);
void HLCD_voidSendCustomCharacter (u8 *Copy_pu8CharectarArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

#endif //  HAL_LCD_LCD_INT_H_
