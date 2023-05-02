/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DIO_program.c
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
 * v1.0		    MAR 22, 2023		Ahmed Essam El-Mogy		Adding Functions
 * v1.1		    MAR 25, 2023		Ahmed Essam El-Mogy		Editing Naming Conventions
 * ----------------------------------------------------------------------------------
 */

/* Library Inclusions */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* Lower Layer Inclusions */
/* ... interfaces of lower layers ... */
/* Self Files Inclusions */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void MDIO_voidSetPinDir(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8Direction)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_BIT(DDRA, Copy_u8PinNum);
					SET_BIT(PORTA, Copy_u8PinNum);
					break;
				case INPUT_NO_PULLUP:
					CLR_BIT(DDRA, Copy_u8PinNum);
					CLR_BIT(PORTA, Copy_u8PinNum);
					break;
				case OUTPUT:
					SET_BIT(DDRA, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_B:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_BIT(DDRB, Copy_u8PinNum);
					SET_BIT(PORTB, Copy_u8PinNum);
					break;
				case INPUT_NO_PULLUP:
					CLR_BIT(DDRB, Copy_u8PinNum);
					CLR_BIT(PORTB, Copy_u8PinNum);
					break;
				case OUTPUT:
					SET_BIT(DDRB, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_C:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_BIT(DDRC, Copy_u8PinNum);
					SET_BIT(PORTC, Copy_u8PinNum);
					break;
				case INPUT_NO_PULLUP:
					CLR_BIT(DDRC, Copy_u8PinNum);
					CLR_BIT(PORTC, Copy_u8PinNum);
					break;
				case OUTPUT:
					SET_BIT(DDRC, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_D:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_BIT(DDRD, Copy_u8PinNum);
					SET_BIT(PORTD, Copy_u8PinNum);
					break;
				case INPUT_NO_PULLUP:
					CLR_BIT(DDRD, Copy_u8PinNum);
					CLR_BIT(PORTD, Copy_u8PinNum);
					break;
				case OUTPUT:
					SET_BIT(DDRD, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8State)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			switch (Copy_u8State)
			{
				case LOW:
					CLR_BIT(PORTA, Copy_u8PinNum);
					break;
				case HIGH:
					SET_BIT(PORTA, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_B:
			switch (Copy_u8State)
			{
				case LOW:
					CLR_BIT(PORTB, Copy_u8PinNum);
					break;
				case HIGH:
					SET_BIT(PORTB, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_C:
			switch (Copy_u8State)
			{
				case LOW:
					CLR_BIT(PORTC, Copy_u8PinNum);
					break;
				case HIGH:
					SET_BIT(PORTC, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_D:
			switch (Copy_u8State)
			{
				case LOW:
					CLR_BIT(PORTD, Copy_u8PinNum);
					break;
				case HIGH:
					SET_BIT(PORTD, Copy_u8PinNum);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		default:
			/* Do Nothing */
			break;
	}
}


void MDIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			TOG_BIT(PORTA, Copy_u8PinNum);
			break;
		case DIO_PORT_B:
			TOG_BIT(PORTB, Copy_u8PinNum);
			break;
		case DIO_PORT_C:
			TOG_BIT(PORTC, Copy_u8PinNum);
			break;
		case DIO_PORT_D:
			TOG_BIT(PORTD, Copy_u8PinNum);
			break;
		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 * Copy_u8State)
{
	u8 Local_u8PinValue;
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			Local_u8PinValue = GET_BIT(PINA, Copy_u8PinNum);
			break;
		case DIO_PORT_B:
			Local_u8PinValue = GET_BIT(PINB, Copy_u8PinNum);
			break;
		case DIO_PORT_C:
			Local_u8PinValue = GET_BIT(PINC, Copy_u8PinNum);
			break;
		case DIO_PORT_D:
			Local_u8PinValue = GET_BIT(PIND, Copy_u8PinNum);
			break;
		default:
			/* Do Nothing */
			break;
	}

	* Copy_u8State = Local_u8PinValue;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue = 0;
	switch(Copy_u8PortName)
	{
		case DIO_PORT_A:
			Local_u8PinValue = GET_BIT(PINA, Copy_u8PinNumber);
		break;
		
		case DIO_PORT_B:
			Local_u8PinValue = GET_BIT(PINB, Copy_u8PinNumber);
		break;
		
		case DIO_PORT_C:
			Local_u8PinValue = GET_BIT(PINC, Copy_u8PinNumber);
		break;

		case DIO_PORT_D:
			Local_u8PinValue = GET_BIT(PIND, Copy_u8PinNumber);
		break;
		default:
			/* Do Nothing*/
		break;
	}
	return Local_u8PinValue;
}

void MDIO_voidSetPortDir(u8 Copy_u8PortName, u8 Copy_u8Direction)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_REG(DDRA);
					SET_REG(PORTA, 0xFF);
					break;
				case INPUT_NO_PULLUP:
					CLR_REG(DDRA);
					CLR_REG(PORTA);
					break;
				case OUTPUT:
					SET_REG(DDRA, 0xFF);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_B:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_REG(DDRB);
					SET_REG(PORTB, 0xFF);
					break;
				case INPUT_NO_PULLUP:
					CLR_REG(DDRB);
					CLR_REG(PORTB);
					break;
				case OUTPUT:
					SET_REG(DDRB, 0xFF);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_C:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_REG(DDRC);
					SET_REG(PORTC, 0xFF);
					break;
				case INPUT_NO_PULLUP:
					CLR_REG(DDRC);
					CLR_REG(PORTC);
					break;
				case OUTPUT:
					SET_REG(DDRC, 0xFF);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_D:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					CLR_REG(DDRD);
					SET_REG(PORTD, 0xFF);
					break;
				case INPUT_NO_PULLUP:
					CLR_REG(DDRD);
					CLR_REG(PORTD);
					break;
				case OUTPUT:
					SET_REG(DDRD, 0xFF);
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidSetPortSpecificDir(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			SET_REG(DDRA, Copy_u8SpecificDirection);
			break;
		case DIO_PORT_B:
			SET_REG(DDRB, Copy_u8SpecificDirection);
			break;
		case DIO_PORT_C:
			SET_REG(DDRC, Copy_u8SpecificDirection);
			break;
		case DIO_PORT_D:
			SET_REG(DDRD, Copy_u8SpecificDirection);
			break;
		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			SET_REG(PORTA, Copy_u8PortValue);
			break;
		case DIO_PORT_B:
			SET_REG(PORTB, Copy_u8PortValue);
			break;
		case DIO_PORT_C:
			SET_REG(PORTC, Copy_u8PortValue);
			break;
		case DIO_PORT_D:
			SET_REG(PORTD, Copy_u8PortValue);
			break;
		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidClrPortValue(u8 Copy_u8PortName)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			CLR_REG(PORTA);
			break;
		case DIO_PORT_B:
			CLR_REG(PORTB);
			break;
		case DIO_PORT_C:
			CLR_REG(PORTC);
			break;
		case DIO_PORT_D:
			CLR_REG(PORTD);
			break;
		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidGetPortValue(u8 Copy_u8PortName, u8 * Copy_u8State)
{
	u8 Local_u8PortValue;
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			Local_u8PortValue = GET_REG(PINA);
			break;
		case DIO_PORT_B:
			Local_u8PortValue = GET_REG(PINB);
			break;
		case DIO_PORT_C:
			Local_u8PortValue = GET_REG(PINC);
			break;
		case DIO_PORT_D:
			Local_u8PortValue = GET_REG(PIND);
			break;
		default:
			/* Do Nothing */
			break;
	}

	*Copy_u8State = Local_u8PortValue;
}

void MDIO_voidTogglePortValue(u8 Copy_u8PortName)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			TOG_REG(PORTA);
			break;
		case DIO_PORT_B:
			TOG_REG(PORTB);
			break;
		case DIO_PORT_C:
			TOG_REG(PORTC);
			break;
		case DIO_PORT_D:
			TOG_REG(PORTD);
			break;
		default:
			/* Do Nothing */
			break;
	}

}

void MDIO_voidSetLowerNibbleDir(u8 Copy_u8PortName, u8 Copy_u8Direction)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					DDRA &= 0xF0;
					PORTA |= 0x0F;
					break;
				case INPUT_NO_PULLUP:
					DDRA &= 0xF0;
					PORTA &= 0xF0;
					break;
				case OUTPUT:
					DDRA |= 0x0F;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_B:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					DDRB &= 0xF0;
					PORTB |= 0x0F;
					break;
				case INPUT_NO_PULLUP:
					DDRB &= 0xF0;
					PORTB &= 0xF0;
					break;
				case OUTPUT:
					DDRB |= 0x0F;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_C:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					DDRC &= 0xF0;
					PORTC |= 0x0F;
					break;
				case INPUT_NO_PULLUP:
					DDRC &= 0xF0;
					PORTC &= 0xF0;
					break;
				case OUTPUT:
					DDRC |= 0x0F;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_D:
			switch (Copy_u8Direction)
			{
				case INPUT_PULLUP:
					DDRD &= 0xF0;
					PORTD |= 0x0F;
					break;
				case INPUT_NO_PULLUP:
					DDRD &= 0xF0;
					PORTD &= 0xF0;
					break;
				case OUTPUT:
					DDRD |= 0x0F;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidSetLowerNibbleValue(u8 Copy_u8PortName, u8 Copy_u8State)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			PORTA |= (0x0F & Copy_u8State);
			break;
		case DIO_PORT_B:
			PORTB |= (0x0F & Copy_u8State);
			break;
		case DIO_PORT_C:
			PORTC |= (0x0F & Copy_u8State);
			break;
		case DIO_PORT_D:
			PORTD |= (0x0F & Copy_u8State);
			break;
		default:
			/* Do Nothing */
			break;
	}
}

void MDIO_voidSetHigherNibbleDir(u8 Copy_u8PortName, u8 Copy_u8State)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			switch (Copy_u8State)
			{
				case INPUT_PULLUP:
					DDRA &= 0x0F;
					PORTA |= 0xF0;
					break;
				case INPUT_NO_PULLUP:
					DDRA &= 0x0F;
					PORTA &= 0x0F;
					break;
				case OUTPUT:
					DDRA |= 0xF0;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_B:
			switch (Copy_u8State)
			{
				case INPUT_PULLUP:
					DDRB &= 0x0F;
					PORTB |= 0xF0;
					break;
				case INPUT_NO_PULLUP:
					DDRB &= 0x0F;
					PORTB &= 0x0F;
					break;
				case OUTPUT:
					DDRB |= 0xF0;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_C:
			switch (Copy_u8State)
			{
				case INPUT_PULLUP:
					DDRC &= 0x0F;
					PORTC |= 0xF0;
					break;
				case INPUT_NO_PULLUP:
					DDRC &= 0x0F;
					PORTC &= 0x0F;
					break;
				case OUTPUT:
					DDRC |= 0xF0;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		case DIO_PORT_D:
			switch (Copy_u8State)
			{
				case INPUT_PULLUP:
					DDRD &= 0x0F;
					PORTD |= 0xF0;
					break;
				case INPUT_NO_PULLUP:
					DDRD &= 0x0F;
					PORTD &= 0x0F;
					break;
				case OUTPUT:
					DDRD |= 0xF0;
					break;
				default:
					/* Do Nothing */
					break;
			}
			break;

		default:
			/* Do Nothing */
			break;
	}
}
void MDIO_voidSetHigherNibbleValue(u8 Copy_u8PortName, u8 Copy_u8State)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORT_A:
			PORTA |= (0xF0 & Copy_u8State);
			break;
		case DIO_PORT_B:
			PORTB |= (0xF0 & Copy_u8State);
			break;
		case DIO_PORT_C:
			PORTC |= (0xF0 & Copy_u8State);
			break;
		case DIO_PORT_D:
			PORTD |= (0xF0 & Copy_u8State);
			break;
		default:
			/* Do Nothing */
			break;
	}
}
