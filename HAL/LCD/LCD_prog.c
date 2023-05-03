
/**
 * @file LCD_prog.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-26
 * @compiler GNU GCC
 * @copyright Copyright (c) 2023
 *
 */
#include <util/delay.h>

/*
 * LIBRARY INCLUSION
*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
 * LOWER LAYER INCLUSION
*/
#include "../../MCAL/DIO/DIO_int.h"

/*
 * SELF FILES INCLUSION
*/

#include "LCD_int.h"
#include "LCD_priv.h"
#include "LCD_config.h"

/*****************************************************************
 ***********FUNCTION IMPLEMENTATION*******************************
 ****************************************************************/
void HLCD_voidInit(void)
{
	#if LCD_INIT_MODE == EIGHT_BIT_MODE
		/**intialize data port**/
		MDIO_voidSetPortSpecificDirection(LCD_DATA_PORT,LCD_ALL_OUTPUT);
		/**initialize control pins as output**/
		MDIO_voidSetPinDirection(LCD_CTRL_PORT , LCD_RS_PIN,OUPUT);
		MDIO_voidSetPinDirection(LCD_CTRL_PORT , LCD_EN_PIN,OUPUT);
		MDIO_voidSetPinDirection(LCD_CTRL_PORT , LCD_RW_PIN,OUPUT);
		/**pooling for 40 seconds**/
		_delay_ms(40);

		/**Send Function Set Command**/
		HLCD_voidSendCommand(FUNCTION_SET_CMD);
		/**Send Display On/Off Control Command**/
		HLCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
		/**Send Display Clear Command**/
		HLCD_voidSendCommand(DISPLAY_CLEAR_CMD);
	#elif LCD_INIT_MODE == FOUR_BIT_MODE
		{
			// task
		}
	#else
        #error("LCD_INIT_MODE Configuration Error")
	#endif
}
static void HLCD_voidSendCommand (u8 Copy_u8Command)
{
	// Clear The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
	// Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
    // Set The Command On The Data/Command Port
	MDIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);

	/****SEND  ENABLE PULSE *****/
	/*Low*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);
	/*HIGH for 2 ms*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	/*Low*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);
}

void HLCD_voidSendData(u8 Copy_u8Data)
{
	// Set The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);
	// Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
    // Set The Command On The Data/Command Port
	MDIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);

	/****SEND  ENABLE PULSE *****/
	/*Low*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);
	/*HIGH for 2 ms*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	/*Low*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);

}

void HLCD_voidClearDisplay(void)
{
	HLCD_voidSendCommand(DISPLAY_CLEAR_CMD);
}

/****************NEW FUNCTIONS***********************/

void HLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8CharacterAddress = 0;
    /*Calculate The Address Of The Character On LCD*/
    if(Copy_u8XPos == 0)
    {
        // @ x = 0 -> Address = Y-Position
        Local_u8CharacterAddress = Copy_u8YPos;
    }
    else if (Copy_u8XPos == 1)
    {
        // @ x = 1 -> Address = Y-Position + 0x40
        Local_u8CharacterAddress = Copy_u8YPos + 0x40;
    }
    else
    {
        // Raise an error
    }
    /*Set The 7th bit in the address variable*/
    SET_BIT(Local_u8CharacterAddress, 7);
    /*Send the address variable as a command*/
    HLCD_voidSendCommand(Local_u8CharacterAddress);
}
void HLCD_voidSendString (u8 *Copy_pu8StringArray)
{
	u8 Local_s8LoopIterator = 0 ;
	while (Copy_pu8StringArray[Local_s8LoopIterator]!= '\0')
	{
		HLCD_voidSendData(Copy_pu8StringArray[Local_s8LoopIterator++]);
	}
}
void HLCD_voidSendNumber (u32 Copy_u32Number)
{
	// assume number of 10 digits
	u8 Local_u8ArrayNumber[10];
	s8 Local_s8LoopIterator = 0 ;
	while (Copy_u32Number != 0 )
	{
		Local_u8ArrayNumber[Local_s8LoopIterator++] = Copy_u32Number%10;
		Copy_u32Number/=10;
	}
	Local_s8LoopIterator-- ;
	while (Local_s8LoopIterator >= 0)
	{
		HLCD_voidSendData (Local_u8ArrayNumber[Local_s8LoopIterator--] + '0');
	}
}

void HLCD_voidSendCustomCharacter (u8 *Copy_pu8CharectarArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	u8 Local_s8LoopIterator ;
	u8 Local_u8CGRAMAddress = 0 ;

	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8 ;
	SET_BIT (Local_u8CGRAMAddress , 6);
	HLCD_voidSendCommand (Local_u8CGRAMAddress);
	for (Local_s8LoopIterator=0 ; Local_s8LoopIterator < 8 ; Local_s8LoopIterator++)
	{
		HLCD_voidSendData (Copy_pu8CharectarArray[Local_s8LoopIterator]);
	}
	HLCD_voidGoToXY (Copy_u8XPosition,Copy_u8YPosition);
	HLCD_voidSendData (Copy_u8PatternNumber);
}


