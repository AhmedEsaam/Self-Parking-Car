#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Timer/Timer_interface.h"

#include "util/delay.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/MOTOR/DC_Motor_interface.h"

#include "../LIB/STD_TYPES.h"


void main(void)
{
    Motor_t motor1 = {
        .MotorClockwisePort = PORTD_ID,
        .MotorClockwisePin = PIN0_ID,
        .MotorAnticlockwisePort = PORTD_ID,
        .MotorAnticlockwisePin = PIN1_ID,
    };

    // LED_t led1 = {PORTA_ID, PIN0_ID};
	// HLED_voidLedInit(&led1);

    // MDIO_voidSetPinDirection(PORTA_ID, PIN0_ID, OUPUT);
    // MDIO_voidSetPinValue(PORTA_ID, PIN0_ID, HIGH);
    
    HMotor_voidMotorInit(&motor1);
    HMotor_voidMotorRotateClockwise(&motor1);

    while(1)
    {


    }
}

