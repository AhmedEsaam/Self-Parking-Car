/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DC_Motor_program.h
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
 
 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "DC_Motor_interface.h"
#include "DC_Motor_config.h"
#include "DC_Motor_private.h"



void HMotor_voidMotorInit(Motor_t* Copy_pMotor_t_Obj)
{
	MDIO_voidSetPinDirection (Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , OUPUT);
	MDIO_voidSetPinDirection (Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , OUPUT);

}
/*
void HMotor_voidMotorRotate(EN_rotation_t Rotate_Direction)
{
	switch(Rotate_Direction)
	{
		case anticlockwise:
			HMotor_voidMotorRotateAnticlockwise(Motor_t* Copy_pMotor_t_Obj);
			break;
		case clockwise:
			HMotor_voidMotorRotateClockwise(Motor_t* Copy_pMotor_t_Obj);
			break;
		default:
		break;
	}
}
*/
void HMotor_voidMotorRotateClockwise(Motor_t* Copy_pMotor_t_Obj)
{
	MDIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , HIGH);
	MDIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , LOW);
}

void HMotor_voidMotorRotateAnticlockwise(Motor_t* Copy_pMotor_t_Obj)
{
	MDIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , LOW);
	MDIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , HIGH);
}

void HMotor_voidMotorStop(Motor_t* Copy_pMotor_t_Obj)
{
	MDIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , LOW);
	MDIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , LOW);
}



// void HMotor_void
