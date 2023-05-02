/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ADC_config.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 30, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 30, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/*Options: 
        LEFT_ADJUST
        RIGHT_ADJUST
*/
#define         ADC_ADJUST_RESULT           LEFT_ADJUST

/*
    Options:
        AREF
        AVCC
        INTERNAL_2v56
*/
#define         ADC_REFERENCE_SELECTION     AREF

/*
    Options:
        DIVISION_FACTOR_2  
        DIVISION_FACTOR_4  
        DIVISION_FACTOR_8  
        DIVISION_FACTOR_16 
        DIVISION_FACTOR_32 
        DIVISION_FACTOR_64 
        DIVISION_FACTOR_128
*/
#define         ADC_PRESCALER_VALUE         DIVISION_FACTOR_128

/*Options:
        ENABLE
        DISBALE
*/
#define         ADC_INTERRUPT_STATUS        ENABLE

/*Options:
        ENABLE
        DISBALE
*/
#define         ADC_ENABLE                  ENABLE


#endif
