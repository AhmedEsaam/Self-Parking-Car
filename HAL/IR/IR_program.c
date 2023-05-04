/*
 * ----------------------------------------------------------------------------------
 * Filename     :	IR_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 4, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 4, 2023		    Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

void IR_voidInit(IR_t *Copy_pIR_tObj)
{
	MDIO_voidSetPinDir(Copy_pIR_tObj->IR_u8PORT, Copy_pIR_tObj->IR_u8PIN, INPUT_NO_PULLUP);
}

void IR_voidGetValue(IR_t *Copy_pIR_tObj, u8 *Copy_pu8IRValue)
{
	MDIO_voidGetPinValue(Copy_pIR_tObj->IR_u8PORT, Copy_pIR_tObj->IR_u8PIN, &Copy_pu8IRValue);
}
