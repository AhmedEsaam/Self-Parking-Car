/*
 * ----------------------------------------------------------------------------------
 * Filename     :	BUTTON_interface.c
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

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

/* Button Connection */
#define PULLUP			0
#define NO_PULLUP		1

typedef struct 
{
	u8 BUTTON_u8PORT;
	u8 BUTTON_u8PIN;
	// u8 BUTTON_u8Connection; /* PULLUP / PULLDOWN */
}BUTTON_t;

void BUTTON_voidInit(BUTTON_t* Copy_pBUTTON_t_Obj);
u8 BUTTON_u8Read(BUTTON_t* Copy_pBUTTON_t_Obj, u8* Copy_pu8Value);

#endif /* BUTTON_INTERFACE_H */
