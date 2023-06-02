/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EXTI_config.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 29, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 29, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/* Options:
    INT0_INPUT_PULLUP
    INT0_INPUT_EXTERNALPULLDOWN
    INT0_INPUT_EXTERNALPULLUP
*/
#define INT0_PIN        INT0_INPUT_PULLUP

/* Options:
    INT1_INPUT_PULLUP
    INT1_INPUT_EXTERNALPULLDOWN
    INT1_INPUT_EXTERNALPULLUP
*/
#define INT1_PIN        INT1_INPUT_PULLUP

/*Options:
    INT2_INPUT_PULLUP
    INT2_INPUT_EXTERNALPULLDOWN
    INT2_INPUT_EXTERNALPULLUP
*/
#define INT2_PIN        INT2_INPUT_PULLUP

#endif /* EXTI_CONFIG_H */