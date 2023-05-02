/*
 * EXTI_int.h
 *
 *  Created on: Apr 14, 2023
 *      Author: doaah
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

/*************************************/
/***********global shared Macros******/
/*************************************/
// EXTI Sense Control Triggers
#define EXTI_TRIG_LOW_LEVEL   0
#define EXTI_TRIG_ANY_CHANGE  1
#define EXTI_TRIG_FALL_EDGE   2
#define EXTI_TRIG_RAIS_EDGE   3

//EXTI Interrupt IDs
#define EXTI_INT0_ID 6
#define EXTI_INT1_ID 7
#define EXTI_INT2_ID 5

/*****************************************/
/***********global shared prototypes******/
/*****************************************/
void M_EXTI_void_Enable(u8 copy_u8IntID, u8 copy_u8Sense);
void M_EXTI_void_Disable(u8 copy_u8IntID);
void M_EXTI_void_setCallBack(void (*ptrfn) (void), u8 copy_u8IntID);


#endif /* MCAL_EXTI_EXTI_INT_H_ */
