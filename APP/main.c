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

#define requiredDistance    50

/* IRs */
static void IRAction(void);
LED_t led1 = {PORTA_ID, PIN7_ID};
EXTI_t ext = {INT0, FALLING_EDGE};

typedef enum {
    Idle, Scanning, Parcking, UnParcking
}states;

void MoveForward(Motor_t* Right, Motor_t* Left)
{
    HMotor_voidMotorRotateClockwise(&Right);
    HMotor_voidMotorRotateClockwise(&Left);
}

// void ForwardRight(Motor_t* Right, Motor_t* Left, u8 Copy_u8SpeedDigitalValue)
// {
//     HMotor_voidMotorStop(&Right);
//     TIMER0_voidSetCTCCompareMatchValue(Copy_u8SpeedDigitalValue); // Left motors 
// }

void BackwardRight(Motor_t* Right, Motor_t* Left, u8 Copy_u8SpeedDigitalValue)
{
    HMotor_voidMotorStop(&Right);
    HMotor_voidMotorRotateAnticlockwise(&Left);
    TIMER0_voidSetCTCCompareMatchValue(Copy_u8SpeedDigitalValue); // Left motors 
}

void BackwardLeft(Motor_t* Right, Motor_t* Left, u8 Copy_u8SpeedDigitalValue)
{
    HMotor_voidMotorStop(&Left);
    HMotor_voidMotorRotateAnticlockwise(&Right);
    TIMER0_voidSetCTCCompareMatchValue(Copy_u8SpeedDigitalValue); // Left motors 
}

int main(void)
{
    states local_u8State = Scanning;

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
        .MotorClockwisePin = PIN2_ID,
        .MotorAnticlockwisePort = PORTD_ID,
        .MotorAnticlockwisePin = PIN3_ID,
    };
    Motor_t LeftMotors = {
        .MotorClockwisePort = PORTD_ID,
        .MotorClockwisePin = PIN0_ID,
        .MotorAnticlockwisePort = PORTD_ID,
        .MotorAnticlockwisePin = PIN1_ID,
    };

    TIMER0_voidInit();
	MDIO_voidSetPinDirection(PORTB_ID, PIN3_ID, OUPUT);

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

        switch (local_u8State)
        {
        case Idle: // Stop
            HMotor_voidMotorStop(&RightMotors);
            HMotor_voidMotorStop(&LeftMotors);
            break;

        case Scanning: // car scans for empty slot while moving forward
//            MoveForward(&RightMotors, &LeftMotors);
            HMotor_voidMotorRotateClockwise(&RightMotors);
            HMotor_voidMotorRotateClockwise(&LeftMotors);

           	TIMER0_voidSetCTCCompareMatchValue(130);


            while(Distance < requiredDistance)
            {
                HULTRASONIC_voidReadDistance(&Distance);
                _delay_ms(400);
            }
            HMotor_voidMotorStop(&RightMotors);
            HMotor_voidMotorStop(&LeftMotors);

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
        	TIMER0_voidSetCTCCompareMatchValue(130);

            /* Sequence */
            break;

        case UnParcking:
            /* Sequence */
            break;
        
        default:
            break;
        }

    }
    return 0;
}


static void IRAction(void)
{
    HLED_voidToggleLed(&led1);
}
