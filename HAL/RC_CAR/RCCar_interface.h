/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RCCar_interface.h
 * Author       :	Abdelrhman Nasr Farag
 * Created on   :	June 3, 2023
 * Version      :	v1.0
  * Compiler     :	AVR GCC
 * Controller   :   ATmega32 (8-bit Architecture)
 * Layer        :   HAL (ECUAL)
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    June 3, 2023		Abdelrhman Nasr Farag		Initial Creation
 * ----------------------------------------------------------------------------------
 */


#ifndef HAL_RCCar_interface_H_
#define HAL_RCCar_interface_H_

#include "../MOTOR/DC_Motor_interface.h"

void HRCCar_VoidCarStop(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);
void HRCCar_VoidForword(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);
void HRCCar_VoidBackword(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);
void HRCCar_VoidBackRight(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);
void HRCCar_VoidBackLeft(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);
void HRCCar_VoidForwordRight(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);
void HRCCar_VoidForwordLeft(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2);






#endif /*HAL_RCCar_interface_H_*/