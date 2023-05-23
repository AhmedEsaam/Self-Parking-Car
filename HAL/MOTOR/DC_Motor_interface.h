/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DC_Motor_interface.h
 * Author       :	Abdelrhman Nasr Farag
 * Created on   :	May 5, 2023
 * Version      :	v1.0
  * Compiler     :	AVR GCC
 * Controller   :   ATmega32 (8-bit Architecture)
 * Layer        :   HAL (ECUAL)
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    May 5, 2023		Abdelrhman Nasr Farag		Initial Creation
 * ----------------------------------------------------------------------------------
 */
 
#ifndef DC_Motor_interface_H_
#define DC_Motor_interface_H_



typedef enum{
	clockwise,
	anticlockwise
	}EN_rotation_t;


typedef struct{
	u8 MotorClockwisePin;
	u8 MotorClockwisePort ;
	u8 MotorAnticlockwisePin ;
	u8 MotorAnticlockwisePort ;
}Motor_t ;


void HMotor_voidMotorInit(Motor_t* Copy_pMotor_t_Obj);
void HMotor_voidMotorRotate(EN_rotation_t Rotate_Direction);
void HMotor_voidMotorRotateClockwise(Motor_t* Copy_pMotor_t_Obj);
void HMotor_voidMotorRotateAnticlockwise(Motor_t* Copy_pMotor_t_Obj);
void HMotor_voidMotorStop(Motor_t* Copy_pMotor_t_Obj);


#endif
