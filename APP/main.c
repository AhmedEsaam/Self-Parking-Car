#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Timer/Timer_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_int.h"

#include "util/delay.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/IR/IR_interface.h"
#include "../HAL/BUTTON/BUTTON_interface.h"
#include "../HAL/MOTOR/DC_Motor_interface.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_int.h"

/* IRs */
static void IRAction(void);
LED_t led1 = {PORTA_ID, PIN7_ID};
EXTI_t ext = {INT0, FALLING_EDGE};

typedef enum {
    Idle, Moving, Parcking, UnParcking
}states;

void main(void)
{
    states local_u8State = Idle;

    /* ULTRASONIC ........................................................... */
    u32 Distance ;
	// enable LCD
	// HLCD_voidInit();
	// enable ULTRASONIC
	// ICU_voidSetTRiggerSignal();
	HULTRASONIC_voidInit();
	// enable GIE
	M_GIE_void_enable();

    /* MOTORS .............................................................. */
    Motor_t RightMotors = {
        .MotorClockwisePort = PORTD_ID,
        .MotorClockwisePin = PIN0_ID,
        .MotorAnticlockwisePort = PORTD_ID,
        .MotorAnticlockwisePin = PIN1_ID,
    };
    Motor_t LeftMotors = {
        .MotorClockwisePort = PORTD_ID,
        .MotorClockwisePin = PIN2_ID,
        .MotorAnticlockwisePort = PORTD_ID,
        .MotorAnticlockwisePin = PIN3_ID,
    };
    HMotor_voidMotorInit(&RightMotors);
    HMotor_voidMotorInit(&LeftMotors);

    /* IRs ...................................................................*/
    IR_t Local_IR1Sensor = {PORTA_ID, PIN2_ID};
	IR_voidInit(&Local_IR1Sensor);

	HLED_voidLedInit(&led1);
    M_GIE_void_enable();
    EXTI_voidInitPinConnection(&ext);
    EXTI_voidTriggerEdge(&ext);
    EXTI_voidEnable(&ext);
    HLED_voidTurnOffLed(&led1);
    EXTI_voidSetCallback(&ext, &IRAction);

    while(1)
    {

        /* Motor */
        // HMotor_voidMotorRotateClockwise(&motor1);
    
        /* Ultrasonic */
        // HULTRASONIC_voidReadDistance(&Distance);
		// HLCD_voidClearDisplay();
		// HLCD_voidSendNumber(Distance);
		// _delay_ms(400);

        switch (states)
        {
        case Idle:
            HMotor_voidMotorStop(&RightMotors);
            HMotor_voidMotorStop(&LeftMotors);
            break;

        case Moving:
            HMotor_voidMotorRotateClockwise(&RightMotors);
            HMotor_voidMotorRotateClockwise(&LeftMotors);

            /* Scan */
            // t1;
            // t2;
            // ditance;
            // if (distance >= required_distance)
            // {
            //     state = parcking;
            // }
            break;

        case Parcking:
            /* Sequence */
            break;

        case UnParcking:
            /* Sequence */
            break;
        
        default:
            break;
        }

    }
}


static void IRAction(void)
{
    HLED_voidToggleLed(&led1);
}
