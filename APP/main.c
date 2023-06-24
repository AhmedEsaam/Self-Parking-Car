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
    Idle, Scanning, Parcking,
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

	 
     while(1)
     { 
		// check car mode state 
    	 switch (local_u8State)
		{
			// if case = idle -> car in stop mode  
			case Idle:
				 HMotor_voidMotorStop(&RightMotors);
				 HMotor_voidMotorStop(&LeftMotors);

			break;
			/*
			* if state is scanning 
			* start the sequance 
			* scan for sufficient  distance every 100 ms
			* after 1000 ms and the distance suitble for parking
			* go to parking mode 
			* if not 
			* start scanning again 
			*/

			case Scanning:
				 if(Distance <= 50)//
				 {
					// get the distance and display it on LCD 
				 	HULTRASONIC_voidReadDistance(&Distance);
		            HLCD_voidSendNumber(Distance);
				 	_delay_ms(100);//
		            HLCD_voidClearDisplay();
				 }
				 else // distance > 50 // read the distance 10 times after find a suitble deapth  
				 {
                    u8 Local_u8Iterator = 0 ;
                    for ( Local_u8Iterator = 0 ; Local_u8Iterator < 10 ; Local_u8Iterator ++ ) // i = 0 
                    {
                        HULTRASONIC_voidReadDistance(&Distance);
                        HLCD_voidSendNumber(Distance);
                        if (Distance < 50)
                        {
                            break; 
                        }
                        _delay_ms(100);
                        HLCD_voidClearDisplay();
                    }
                    
					// if the ultrasonic find an object then reset scanning mood 
                    if (Local_u8Iterator != 10)
                    {
                        local_u8State = Scanning;
                    }
                    else/ // if not then start the sequance of parking 
                    {
                        HMotor_voidMotorStop(&RightMotors);
                        HMotor_voidMotorStop(&LeftMotors);
                        _delay_ms(700);//
                        local_u8State = Parcking;
                    }
				}

			break;
			case Parcking:
					// move back right with suitble angle 
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

					// move back left with the same angle and same length 
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
					// back to idle mode 
					 local_u8State = Idle;
//				}
			break;
			default:
			break;
		}
     }
}

/*isr function to back to the if the ir find object while parking */

static void intAction(void)
{
	// back to idle moode 
	 local_u8State = Idle;
	 HMotor_voidMotorStop(&RightMotors);
	 HMotor_voidMotorStop(&LeftMotors);
	_delay_ms(100);
	
	

}



