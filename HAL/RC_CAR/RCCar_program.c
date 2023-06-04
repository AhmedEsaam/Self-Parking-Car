/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RCCar_program.h
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
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include"../../MCAL/DIO/DIO_int.h"
#include "../MOTOR/DC_Motor_interface.h"

#include"RCCar_interface.h"
#include"RCCar_confige.h"
#include"RCCar_private.h"


void HRCCar_VoidCarStop(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
    			 HMotor_voidMotorStop(&Copy_pMotor_t_Obj_1);
				 HMotor_voidMotorStop(&Copy_pMotor_t_Obj_2);
}
void HRCCar_VoidForword(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
                 HMotor_voidMotorRotateAnticlockwise(&Copy_pMotor_t_Obj_1);
				 HMotor_voidMotorRotateAnticlockwise(&Copy_pMotor_t_Obj_2);

}
void HRCCar_VoidBackword(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
                 HMotor_voidMotorRotateClockwise(&Copy_pMotor_t_Obj_1);
				 HMotor_voidMotorRotateClockwise(&Copy_pMotor_t_Obj_2);
}
void HRCCar_VoidBackRight(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
                 HMotor_voidMotorStop(&Copy_pMotor_t_Obj_1);
                 HMotor_voidMotorRotateClockwise(&Copy_pMotor_t_Obj_2);
}
void HRCCar_VoidBackLeft(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
                 HMotor_voidMotorStop(&Copy_pMotor_t_Obj_2);
	  			 HMotor_voidMotorRotateClockwise(&Copy_pMotor_t_Obj_1);
}
void HRCCar_VoidForwordRight(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
                 HMotor_voidMotorStop(&Copy_pMotor_t_Obj_1);
                 HMotor_voidMotorRotateAnticlockwise(&Copy_pMotor_t_Obj_2):
}
void HRCCar_VoidForwordLeft(Motor_t* Copy_pMotor_t_Obj_1,Motor_t* Copy_pMotor_t_Obj_2)
{
                 HMotor_voidMotorStop(&Copy_pMotor_t_Obj_2);
	  			 HMotor_voidMotorRotateAnticlockwise(&Copy_pMotor_t_Obj_1);
}
