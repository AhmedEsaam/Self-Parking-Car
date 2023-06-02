/**
 * @file DIO_int.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief DIO Driver for ATMEGA32 
 * @version 0.1
 * @date 2023-03-25
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define PORTA_ID  1
#define PORTB_ID  2
#define PORTC_ID  3
#define PORTD_ID  4

#define INPUT    0
#define OUPUT    1

#define PIN0_ID  0
#define PIN1_ID  1
#define PIN2_ID  2
#define PIN3_ID  3
#define PIN4_ID  4
#define PIN5_ID  5
#define PIN6_ID  6
#define PIN7_ID  7

#define LOW  0
#define HIGH 1

#define PULLUP     1 // as HIGH 
#define NOPULLUP   0 // as LOW

/**
 * @brief Set Pin Direction For a specific pin  
 * @param Copy_u8PortName  choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8PinNumber choose from (PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID, 
 *                          PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID )
 * @param Copy_u8Direction choose from (OUTPUT, INPUT)
 */
void MDIO_voidSetPinDirection (u8 Copy_u8PortName ,u8 Copy_u8PinNumber , u8 Copy_u8Direction);

/**
 * @brief Set Pin Value For a specific pin
 * @param Copy_u8PortName  choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8PinNumber choose from (PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID, 
 *                          PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID )
 * @param Copy_u8Value choose from ( LOW or HIGH)
 */
void MDIO_voidSetPinValue (u8 Copy_u8PortName ,u8 Copy_u8PinNumber , u8 Copy_u8Value);

/**
 * @brief TogglePin Value For a specific pin
 * @param Copy_u8PortName  choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8PinNumber choose from (PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID,
 *                          PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID )
 */
void MDIO_voidTogglePin (u8 Copy_u8PortName ,u8 Copy_u8PinNumber );

/**
 * @brief Read Pin Value 
 * @param Copy_u8PortName  choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8PinNumber choose from (PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID, 
 *                          PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID )
 * @return U8 
 */
u8   MDIO_voidReadPinValue (u8 Copy_u8PortName ,u8 Copy_u8PinNumber);

/**
 * @brief Set Port Specific Direction
 * @param Copy_u8PortName  choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8Direction number from 0 to 255
 * @return U8
 */
void MDIO_voidSetPortSpecificDirection (u8 Copy_u8PortName , u8 Copy_u8SpecificDirection);

/**
 * @brief Set Port Direction
 * @param Copy_u8PortName  choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8Direction choose from (INPUT, OUPUT)
 * @return U8
 */
void MDIO_voidSetPortDirection (u8 Copy_u8PortName , u8 Copy_u8Direction);

/**
 * @brief Set Port Value
 * @param Copy_u8PortName   choose from (PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @param Copy_u8Value 		write any number from 0 to 255
 * @return U8
 */
void MDIO_voidSetPortValue (u8 Copy_u8PortName , u8 Copy_u8Value);

/**
 * @brief Get Port Value
 * @param Copy_u8PortName   choose from(PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID)
 * @return U8 number from 0 to 255
 */
u8 MDIO_voidGetPortValue (u8 Copy_u8PortName);

#endif /* MCAL_DIO_DIO_INT_H_ */
