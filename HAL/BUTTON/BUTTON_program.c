/*
 * ----------------------------------------------------------------------------------
 * Filename     :	BUTTON_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * v1.1		    MAR 30, 2023		Ahmed Essam El-Mogy		Adding Button Action Function
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"

//#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "BUTTON_interface.h"
#include "BUTTON_private.h"
#include "BUTTON_config.h"


void BUTTON_voidInit(BUTTON_t* Copy_pBUTTON_t_Obj)
{
	switch (Copy_pBUTTON_t_Obj->BUTTON_u8Connection)
	{
	case PULLUP:
		MDIO_voidSetPinDir(Copy_pBUTTON_t_Obj->BUTTON_u8PORT, Copy_pBUTTON_t_Obj->BUTTON_u8PIN, INPUT_PULLUP);
		break;
	case NO_PULLUP:
		MDIO_voidSetPinDir(Copy_pBUTTON_t_Obj->BUTTON_u8PORT, Copy_pBUTTON_t_Obj->BUTTON_u8PIN, INPUT_NO_PULLUP);
		break;

	default:
		break;
	}
}

void BUTTON_voidRead(BUTTON_t* Copy_pBUTTON_t_Obj, u8* Copy_pu8Value)
{
	MDIO_voidGetPinValue(Copy_pBUTTON_t_Obj->BUTTON_u8PORT, Copy_pBUTTON_t_Obj->BUTTON_u8PIN, &Copy_pu8Value);
}
