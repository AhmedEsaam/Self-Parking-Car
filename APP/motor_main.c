#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Timer/Timer_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_int.h"

#include "util/delay.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/MOTOR/DC_Motor_interface.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_int.h"

#include "../LIB/STD_TYPES.h"

typedef enum {
    Idle, Scanning, Parcking, UnParcking
}states;


void main(void)
{
    states local_u8State = Scanning;

	u32 Distance =0;
		// enable ULTRASONIC
		// ICU_voidSetTRiggerSignal();
	HULTRASONIC_voidInit();
		// enable GIE
	M_GIE_void_enable();
	// enable lcd
    HLCD_voidInit();

		//      /////////////////////
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
    HMotor_voidMotorInit(&RightMotors);
    HMotor_voidMotorInit(&LeftMotors);


    HMotor_voidMotorRotateAnticlockwise(&RightMotors);
    HMotor_voidMotorRotateAnticlockwise(&LeftMotors);

    TIMER0_voidInit();
	MDIO_voidSetPinDirection(PORTB_ID, PIN3_ID, OUPUT);
	 TIMER0_voidSetCTCCompareMatchValue(121);


     while(1)
     {
//       measure distance
		 if(Distance <= 50)//
		 {
		 	HULTRASONIC_voidReadDistance(&Distance);
             HLCD_voidSendNumber(Distance);
		 	_delay_ms(100);//
            HLCD_voidClearDisplay();
		 }
		 else
		 {
//			 _delay_ms(1000);//
			 HMotor_voidMotorStop(&RightMotors);
			 HMotor_voidMotorStop(&LeftMotors);
		 }


        // parcking
//		TIMER0_voidSetCTCCompareMatchValue(130);
        // forward
//        HMotor_voidMotorRotateClockwise(&RightMotors);
//        HMotor_voidMotorRotateClockwise(&LeftMotors);
//        _delay_ms(3000);
        // back 
//        HMotor_voidMotorRotateAnticlockwise(&RightMotors);
//        HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
//        _delay_ms(300);

//        for (int i=0; i <9; i++)
//        {
//            HMotor_voidMotorStop(&RightMotors);
//            HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
//            _delay_ms(100);
//            // back
//            HMotor_voidMotorRotateAnticlockwise(&RightMotors);
//            HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
//            _delay_ms(100);
//        }
//
//        //back left
//        for (int i=0; i <9; i++)
//        {
//            HMotor_voidMotorStop(&LeftMotors);
//            HMotor_voidMotorRotateAnticlockwise(&RightMotors);
//            _delay_ms(100);
//            // back
//            HMotor_voidMotorRotateAnticlockwise(&RightMotors);
//            HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
//            _delay_ms(100);
//        }


//        _delay_ms();
//
//        HMotor_voidMotorStop(&LeftMotors);
//        HMotor_voidMotorStop(&RightMotors);
//        _delay_ms(500);

     }
//    while(1)
//    {
//        HMotor_voidMotorStop(&RightMotors);
//        HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
//    }
}

