/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DIO_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Version      :	v1.1
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 22, 2023		Ahmed Essam El-Mogy		Adding Prototypes
 * v1.1		    MAR 25, 2023		Ahmed Essam El-Mogy		Editing Naming Conventions
 * ----------------------------------------------------------------------------------
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

// Ports
#define DIO_PORT_A  'A'
#define DIO_PORT_B  'B'
#define DIO_PORT_C  'C'
#define DIO_PORT_D  'D'

// Pins
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

// Values
#define INPUT	    0
#define OUTPUT	    1

#define LOW		    0
#define HIGH	    1

#define INPUT_PULLUP      'P'
#define INPUT_NO_PULLUP   'N'


// Function Prototypes
void MDIO_voidSetPinDir(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8Direction);
void MDIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8State);
void MDIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum);
void MDIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 * Copy_u8State);
u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

void MDIO_voidSetPortDir(u8 Copy_u8PortName, u8 Copy_u8Direction);
void MDIO_voidSetPortSpecificDir(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection);
void MDIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);
void MDIO_voidClrPortValue(u8 Copy_u8PortName);
void MDIO_voidGetPortValue(u8 Copy_u8PortName, u8 * Copy_u8State);
void MDIO_voidTogglePortValue(u8 Copy_u8PortName);

void MDIO_voidSetLowerNibbleDir(u8 Copy_u8PortName, u8 Copy_u8Direction);
void MDIO_voidSetLowerNibbleValue(u8 Copy_u8PortName, u8 Copy_u8State);

void MDIO_voidSetHigherNibbleDir(u8 Copy_u8PortName, u8 Copy_u8State);
void MDIO_voidSetHigherNibbleValue(u8 Copy_u8PortName, u8 Copy_u8State);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
