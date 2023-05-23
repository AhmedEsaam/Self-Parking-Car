/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
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
 * v1.1		    MAR 30, 2023		Ahmed Essam El-Mogy		Adding ISRs
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_int.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* Global Array Of 3 Pointers To Function For External Interrupts */
static void (*EXTI_pvoidINTNotificationFunction [3]) (void) = {NULL};

void EXTI_voidInitPinConnection(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        #if INT0_PIN == INT0_INPUT_PULLUP
    		MDIO_voidSetPinDirection(EXTI0_PORT, EXTI0_PIN, INPUT);
            MDIO_voidSetPinValue(EXTI0_PORT, EXTI0_PIN, HIGH);
        #elif INT0_PIN == INT0_INPUT_EXTERNALPULLDOWN
            MDIO_voidSetPinDirection(EXTI0_PORT, EXTI0_PIN, INPUT);
        #elif INT0_PIN == INT0_INPUT_EXTERNALPULLUP
            MDIO_voidSetPinDirection(EXTI0_PORT, EXTI0_PIN, INPUT);
        #endif
        break;

    case INT1:
        #if INT1_PIN == INT0_INPUT_PULLUP
            MDIO_voidSetPinDirection(EXTI1_PORT, EXTI1_PIN, INPUT);
            MDIO_voidSetPinValue(EXTI1_PORT, EXTI1_PIN, HIGH);
        #elif INT1_PIN == INT0_INPUT_EXTERNALPULLDOWN
            MDIO_voidSetPinDirection(EXTI1_PORT, EXTI1_PIN, INPUT);
        #elif INT1_PIN == INT0_INPUT_EXTERNALPULLUP
            MDIO_voidSetPinDirection(EXTI1_PORT, EXTI1_PIN, INPUT);
        #endif
        break;

    case INT2:
        #if INT2_PIN == INT0_INPUT_PULLUP
    		MDIO_voidSetPinDirection(EXTI2_PORT, EXTI2_PIN, INPUT);
            MDIO_voidSetPinValue(EXTI2_PORT, EXTI2_PIN, HIGH);
        #elif INT2_PIN == INT0_INPUT_EXTERNALPULLDOWN
            MDIO_voidSetPinDirection(EXTI2_PORT, EXTI2_PIN, INPUT);
        #elif INT2_PIN == INT0_INPUT_EXTERNALPULLUP
            MDIO_voidSetPinDirection(EXTI2_PORT, EXTI2_PIN, INPUT);
        #endif
        break;
    
    default:
        break;
    }
}

void EXTI_voidTriggerEdge(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        MCUCR &= ~(0x03);   /* Clear First Two Least Significant Bits (Bit 0, Bit 1) */
        MCUCR |= (Copy_pEXTI_t_Obj->EXTI_u8IntSense); /* Set Bits of Interrupt Sense In those Positions */
        break;

    case INT1:
        MCUCR &= ~(0x0C);   /* Clear Second Two Least Significant Bits (Bit 2, Bit 3)*/
        MCUCR |= ((Copy_pEXTI_t_Obj->EXTI_u8IntSense) << 2);  /* Set Bits of Interrupt Sense In those Positions */
        break;

    case INT2:
        switch (Copy_pEXTI_t_Obj->EXTI_u8IntSense)
        {
        case FALLING_EDGE:
            CLR_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        default:
            /* Do Nothing */
            break;
        }
        break;

    default:
        /* Do Nothing */
        break;
    }
}

void EXTI_voidEnable(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        SET_BIT(GICR, GICR_INT0);
        break;
    case INT1:
        SET_BIT(GICR, GICR_INT1);
        break;
    case INT2:
        SET_BIT(GICR, GICR_INT2);
        break;
    default:
        break;
    }
}
void EXTI_voidDisable(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        CLR_BIT(GICR, GICR_INT0);
        break;
    case INT1:
        CLR_BIT(GICR, GICR_INT1);
        break;
    case INT2:
        CLR_BIT(GICR, GICR_INT2);
        break;
    default:
        break;
    }
}

void EXTI_voidSetCallback(EXTI_t* Copy_pEXTI_t_Obj, void (*NotificationFunction) (void))
{
    EXTI_pvoidINTNotificationFunction[Copy_pEXTI_t_Obj->EXTI_u8IntNum] = NotificationFunction;
}


/* ISR For INT0 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
    if(EXTI_pvoidINTNotificationFunction[INT0] != NULL)
    {
        /* Invoke The Global Pointer To Function */
        EXTI_pvoidINTNotificationFunction[INT0]();
    }
    else
    {
        /* Do Nothing */
    }
}

/* ISR For INT1 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
    if(EXTI_pvoidINTNotificationFunction[INT1] != NULL)
    {
        /* Invoke The Global Pointer To Function */
        EXTI_pvoidINTNotificationFunction[INT1]();
    }
    else
    {
        /* Do Nothing */
    }
}

/* ISR For INT2 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
    if(EXTI_pvoidINTNotificationFunction[INT2] != NULL)
    {
        /* Invoke The Global Pointer To Function */
        EXTI_pvoidINTNotificationFunction[INT2]();
    }
    else
    {
        /* Do Nothing */
    }
}
