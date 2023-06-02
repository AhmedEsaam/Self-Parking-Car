/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_config.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/*
    Options:
        TIMER_STOP                    
        DIVISION_FACTOR_1             
        DIVISION_FACTOR_8             
        DIVISION_FACTOR_64            
        DIVISION_FACTOR_256           
        DIVISION_FACTOR_1024          
        TIMER_EXTERNAL_T0_FALLING_EDGE
        TIMER_EXTERNAL_T0_RISING_EDGE
*/
#define         TIMER_PRESCALER_VALUE         DIVISION_FACTOR_8

// Set mode and comp output

#endif /* TIMER_CONFIG_H */