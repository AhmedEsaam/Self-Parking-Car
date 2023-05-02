/*
 * TIMER0_config.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Abdelrahman Nasr
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_



/*Option
        CLOCK_16MHZ
        CLOCK_8MHZ
        CLOCK_4MHZ
        CLOCK_2MHZ
        CLOCK_1MHZ
*/
#define CPU_CLOCK       CLOCK_8MHZ

/*Options:
        TIMER0_NORMAL_MODE
        TIMER0_FAST_MODE
        TIMER0_CTC_MODE
        TIMER0_PHASE_CORRECT_MODE
*/
#define TIMER0_MODE_SELECTION   TIMER0_NORMAL_MODE

/*Options:
        SCLAER_TIMER_STOP
        SCLAER_1
        SCLAER_8
        SCLAER_64
        SCLAER_256
        SCLAER_1024
        EXTERNAL_FALLING_EDGE
        EXTERNAL_RISING_EDGE
*/
#define TIMER0_SCALER_SELECT    SCLAER_8


/*Option:
        OCR0_DISCONECTED
        OCR0_TOGGLE
        OCR0_CLEAR
        OCR0_SET
*/
#define TIMER0_OCR_PIN_MODE     OCR0_DISCONECTED



#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
