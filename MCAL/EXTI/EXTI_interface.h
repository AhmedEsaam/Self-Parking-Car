/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EXTI_interface.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 29, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 29, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Interrupt Sense */
#define LOW_LEVEL        0
#define CHANGING_EDGE    1
#define FALLING_EDGE     2
#define RISING_EDGE      3

/* External Interrupt Pins */
#define INT0             0
#define INT1             1
#define INT2             2

typedef struct 
{
	u8 EXTI_u8IntNum;
	u8 EXTI_u8IntSense;
}EXTI_t;

void EXTI_voidInitPinConnection(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidTriggerEdge(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidEnable(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidDisable(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidSetCallback(EXTI_t* Copy_pEXTI_t_Obj, void (*NotificationFunction) (void));


#endif /* EXTI_INTERFACE_H */
