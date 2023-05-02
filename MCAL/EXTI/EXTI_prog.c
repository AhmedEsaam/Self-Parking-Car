/*
 * EXTI_prog.c
 *
 *  Created on: Apr 14, 2023
 *      Author: doaah
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"

// array of 3 pointers to functions (Call Back fn )
static void (*Arr_CallBack[3]) (void)={NULL,NULL,NULL};

void M_EXTI_void_Enable(u8 copy_u8IntID, u8 copy_u8Sense)
{
    // step 1 : config Sense
	if(copy_u8Sense < EXTI_TRIG_LOW_LEVEL  || copy_u8Sense > EXTI_TRIG_RAIS_EDGE )
	{
		return ;
	}
	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
		// step 1 : Apply Mask
		MCUCR_REG &= EXTI_INT0_TRIG_MASK;
		// step 2 : insert value
		MCUCR_REG |= copy_u8Sense;
		break;
	case EXTI_INT1_ID:
		// step 1 : Apply Mask
		MCUCR_REG &= EXTI_INT1_TRIG_MASK;
		// step 2 : insert value
		MCUCR_REG |= copy_u8Sense << EXTI_INT1_TRIG_SHIFT ;
		break;
	case EXTI_INT2_ID:
		// step 1 : Apply Mask
		CLR_BIT(MCUCSR_REG , ISC2_BIT);
		// step 2 : insert value
		MCUCSR_REG |= (GET_BIT(copy_u8Sense,0))<< EXTI_INT2_TRIG_SHIFT;
		break;
	}

	// step 2 : Enable PIE
	if(copy_u8IntID>= EXTI_INT2_ID && copy_u8IntID <= EXTI_INT1_ID)
	   SET_BIT(GICR_REG ,copy_u8IntID);
}

void M_EXTI_void_Disable(u8 copy_u8IntID)
{
	// Method 1
	/*switch (copy_u8IntID)
	{
	case EXTI_INT0_ID:
		CLR_BIT(GICR_REG  ,INT0_BIT);
		break;
	case EXTI_INT1_ID:
		CLR_BIT(GICR_REG  ,INT1_BIT);
		break;
	case EXTI_INT2_ID:
		CLR_BIT(GICR_REG  ,INT2_BIT);
		break;
	}*/
	// Method 2
	if(copy_u8IntID>= EXTI_INT2_ID && copy_u8IntID <= EXTI_INT1_ID)
	   CLR_BIT(GICR_REG ,copy_u8IntID);
}
void M_EXTI_void_setCallBack(void (*ptrfn) (void), u8 copy_u8IntID)
{
   switch(copy_u8IntID)
   {
   case EXTI_INT0_ID:
	   Arr_CallBack[0]= ptrfn;
   		break;
   	case EXTI_INT1_ID:
   		Arr_CallBack[1]= ptrfn;
   		break;
   	case EXTI_INT2_ID:
   		Arr_CallBack[2]= ptrfn;
   		break;
   }
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
    if(Arr_CallBack[0] != NULL)
    {
    	Arr_CallBack[0]();
    }
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
    if(Arr_CallBack[1] != NULL)
    {
    	Arr_CallBack[1]();
    }
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
    if(Arr_CallBack[2] != NULL)
    {
    	Arr_CallBack[2]();
    }
}
