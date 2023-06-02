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
#include "../HAL/IR/IR_interface.h"


#include "../LIB/STD_TYPES.h"

static void intAction(void);
EXTI_t ext = {INT0, FALLING_EDGE};

typedef enum {
    Idle, Scanning, Parcking, UnParcking
}states;

states local_u8State = Scanning;

Motor_t RightMotors = {
    .MotorClockwisePort = PORTD_ID,
    .MotorClockwisePin = PIN4_ID,
    .MotorAnticlockwisePort = PORTD_ID,
    .MotorAnticlockwisePin = PIN3_ID,
};

Motor_t LeftMotors = {
    .MotorClockwisePort = PORTD_ID,
    .MotorClockwisePin = PIN0_ID,
    .MotorAnticlockwisePort = PORTD_ID,
    .MotorAnticlockwisePin = PIN1_ID,
};

void main(void)
{

	u32 Distance =0;
		// enable ULTRASONIC
	HULTRASONIC_voidInit();
		// enable GIE
	M_GIE_void_enable();
	// enable lcd
    HLCD_voidInit();


    HMotor_voidMotorInit(&RightMotors);
    HMotor_voidMotorInit(&LeftMotors);


	 HMotor_voidMotorRotateAnticlockwise(&RightMotors);
	 HMotor_voidMotorRotateAnticlockwise(&LeftMotors);



	TIMER0_voidInit();
	MDIO_voidSetPinDirection(PORTB_ID, PIN3_ID, OUPUT);
	 TIMER0_voidSetCTCCompareMatchValue(150);

//	 ir
	 IR_t Local_IR1Sensor = {PORTD_ID, PIN2_ID};
	 IR_voidInit(&Local_IR1Sensor);

	 EXTI_voidInitPinConnection(&ext);
	 EXTI_voidTriggerEdge(&ext);
	 EXTI_voidEnable(&ext);
	 EXTI_voidSetCallback(&ext, &intAction);

	 u8 Local_u8Counter;

     while(1)
     {
    	 switch (local_u8State)
		{
			case Idle:
				 HMotor_voidMotorStop(&RightMotors);
				 HMotor_voidMotorStop(&LeftMotors);

			break;
			case Scanning:
				 if(Distance <= 50)//
				 {
				 	HULTRASONIC_voidReadDistance(&Distance);
		             HLCD_voidSendNumber(Distance);
				 	_delay_ms(100);//
		            HLCD_voidClearDisplay();
				 }
				 else
				 {
					 _delay_ms(1000);//
					 HMotor_voidMotorStop(&RightMotors);
					 HMotor_voidMotorStop(&LeftMotors);
					 _delay_ms(700);//
					 local_u8State = Parcking;
				 }

			break;
			case Parcking:
//				// check available slot
//				HULTRASONIC_voidReadDistance(&Distance);
//				if (Distance<= 50)
//				{
//					local_u8State = Scanning;
//				}
//				else
//				{
					for (int i=0; i <2; i++)
					{
						HMotor_voidMotorStop(&RightMotors);
						HMotor_voidMotorRotateClockwise(&LeftMotors);
						_delay_ms(700);
						// back
						HMotor_voidMotorRotateClockwise(&RightMotors);
						HMotor_voidMotorRotateClockwise(&LeftMotors);
						_delay_ms(100);
					}

					//back left
					for (int i=0; i <2; i++)
					{
						HMotor_voidMotorStop(&LeftMotors);
						HMotor_voidMotorRotateClockwise(&RightMotors);
						_delay_ms(700);
						// back
						HMotor_voidMotorRotateClockwise(&RightMotors);
						HMotor_voidMotorRotateClockwise(&LeftMotors);
						_delay_ms(100);
					}
					 local_u8State = Idle;
//				}
			break;
			default:
			break;
		}
     }
}


static void intAction(void)
{
	 local_u8State = Idle;
	 HMotor_voidMotorStop(&RightMotors);
	 HMotor_voidMotorStop(&LeftMotors);
	_delay_ms(100);
	 HMotor_voidMotorRotateAnticlockwise(&RightMotors);
	 HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
	_delay_ms(200);
	 HMotor_voidMotorStop(&RightMotors);
	 HMotor_voidMotorStop(&LeftMotors);

	 while(1);
}



