/**
 * @file DIO_prog.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief DIO Driver for ATMEGA32 
 * @version 2.0 add some functions
 * 				1) MDIO_voidTogglePin
 * 				2) MDIO_voidSetPortSpecificDirection
 * 				3) MDIO_voidSetPortValue
 * 				4) MDIO_voidGetPortValue
 * @date 2023-03-25
 * @compiler GNU GCC
 * @copyright Copyright (c) 2023
 * 
 */

/*
 * LIBRARY INCLUSION
*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
 * LOWER LIBRERY INCLUSION 
*/


/*
 * SELF FILES INCLUSION  
*/
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"

/*****************************************************************
 ***********FUNCTION IMPLEMENTATION*******************************
 ****************************************************************/
void MDIO_voidSetPinDirection (u8 Copy_u8PortName ,u8 Copy_u8PinNumber , u8 Copy_u8Direction)
{
    switch (Copy_u8PortName)
    {
        case (PORTA_ID):
            if (Copy_u8Direction == OUPUT)
            {
                SET_BIT (DDRA,Copy_u8PinNumber );

            }
            else if (Copy_u8Direction == INPUT)
            {
                CLR_BIT (DDRA,Copy_u8PinNumber );

            }
            else 
            {
                // do nothing 
            }
        break ;
        case (PORTB_ID)  :
            if (Copy_u8Direction == OUPUT)
            {
                SET_BIT (DDRB,Copy_u8PinNumber );
            }
            else if (Copy_u8Direction == INPUT)
            {
                CLR_BIT (DDRB,Copy_u8PinNumber );
            }
            else 
            {
                // do nothing 
            }
        break;
        case (PORTC_ID):
            if (Copy_u8Direction == OUPUT)
            {
                SET_BIT (DDRC,Copy_u8PinNumber );

            }
            else if (Copy_u8Direction == INPUT)
            {
                CLR_BIT (DDRC,Copy_u8PinNumber );

            }
            else 
            {
                // do nothing 
            }
        break;
        case (PORTD_ID):
            if (Copy_u8Direction == OUPUT)
            {
                SET_BIT (DDRD,Copy_u8PinNumber );

            }
            else if (Copy_u8Direction == INPUT)
            {
                CLR_BIT (DDRD,Copy_u8PinNumber );

            }
            else 
            {
                // do nothing 
            }
        break;


    }
}

void MDIO_voidSetPinValue (u8 Copy_u8PortName ,u8 Copy_u8PinNumber , u8 Copy_u8Value)
{
    switch (Copy_u8PortName)
    {
        case (PORTA_ID):
            switch (Copy_u8Value )
            {
				case LOW:
					CLR_BIT (PORTA,Copy_u8PinNumber );
					break;
				case HIGH:
					SET_BIT (PORTA,Copy_u8PinNumber );
					break;
				default:
					break;
            }
        	break;
        case (PORTB_ID):
        
            switch (Copy_u8Value )
            {
            case LOW:
                CLR_BIT (PORTB,Copy_u8PinNumber );
                break;
            case HIGH:
                SET_BIT (PORTB,Copy_u8PinNumber );
                break;
            default:
                break;
            }
        break;
        case (PORTC_ID):
            switch (Copy_u8Value )
            {
				case LOW:
					CLR_BIT (PORTC,Copy_u8PinNumber );
					break;
				case HIGH:
					SET_BIT (PORTC,Copy_u8PinNumber );
					break;
				default:
					break;
            }
        	break;
        case (PORTD_ID):
            switch (Copy_u8Value )
            {
				case LOW:
					CLR_BIT (PORTD,Copy_u8PinNumber );
					break;
				case HIGH:
					SET_BIT (PORTD,Copy_u8PinNumber );
					break;
				default:
					break;
            }
        	break;
    }
}

u8   MDIO_voidReadPinValue (u8 Copy_u8PortName ,u8 Copy_u8PinNumber)
{
    u8 Local_u8PinValue ;
    switch (Copy_u8PortName )
    {
    case PORTA_ID:
        Local_u8PinValue = GET_BIT (PINA, Copy_u8PinNumber); break;
    case PORTB_ID:
        Local_u8PinValue = GET_BIT (PINB, Copy_u8PinNumber); break;
    case PORTC_ID:
        Local_u8PinValue = GET_BIT (PINC, Copy_u8PinNumber); break;
    case PORTD_ID:
        Local_u8PinValue = GET_BIT (PIND, Copy_u8PinNumber); break;
    default: break;
    }
    return Local_u8PinValue ;
}

void MDIO_voidTogglePin (u8 Copy_u8PortName ,u8 Copy_u8PinNumber )
{
	switch (Copy_u8PortName)
	{
	case PORTA_ID:
		TOG_BIT(PORTA,Copy_u8PinNumber); break;
	case PORTB_ID:
		TOG_BIT(PORTB,Copy_u8PinNumber); break;
	case PORTC_ID:
		TOG_BIT(PORTC,Copy_u8PinNumber); break;
	case PORTD_ID:
		TOG_BIT(PORTD,Copy_u8PinNumber); break;
	}
}
void MDIO_voidSetPortDirection (u8 Copy_u8PortName , u8 Copy_u8Direction)
{
	switch (Copy_u8PortName)
		{
		case PORTA_ID:
			switch (Copy_u8Direction)
			{
			case OUPUT:
				DDRA = 0xFF;
				break ;
			case INPUT:
				DDRA = 0x00;
				break ;
			default :
				break ;
			}
			break ;
		case PORTB_ID:
			switch (Copy_u8Direction)
			{
			case OUPUT:
				DDRB = 0xFF;
				break ;
			case INPUT:
				DDRB = 0x00;
				break ;
			default :
				break ;
			}
			break ;
		case PORTC_ID:
			switch (Copy_u8Direction)
			{
			case OUPUT:
				DDRC = 0xFF;
				break ;
			case INPUT:
				DDRC = 0x00;
				break ;
			default :
				break ;
			}
			break ;
		case PORTD_ID:
			switch (Copy_u8Direction)
			{
			case OUPUT:
				DDRD = 0xFF;
				break ;
			case INPUT:
				DDRD = 0x00;
				break ;
			default :
				break ;
			}
			break ;
		default :
			// do nothing
			break ;
		}
}

void MDIO_voidSetPortSpecificDirection (u8 Copy_u8PortName , u8 Copy_u8SpecificDirection)
{
	switch (Copy_u8PortName)
		{
		case PORTA_ID:
			SET_REG(DDRA, Copy_u8SpecificDirection);
			break ;
		case PORTB_ID:
			SET_REG(DDRB, Copy_u8SpecificDirection);
			break ;
		case PORTC_ID:
			SET_REG(DDRC, Copy_u8SpecificDirection);
			break ;
		case PORTD_ID:
			SET_REG(DDRD, Copy_u8SpecificDirection);
			break ;
		default :
			// do nothing
			break ;
		}
}
void MDIO_voidSetPortValue (u8 Copy_u8PortName , u8 Copy_u8Value)
{
	switch (Copy_u8PortName)
		{
		case PORTA_ID:
			PORTA = Copy_u8Value; // equal to SET_REG(PORTA, Copy_u8Value);
			break;
		case PORTB_ID:
			PORTB = Copy_u8Value;
			break ;
		case PORTC_ID:
			PORTC = Copy_u8Value;
			break;
		case PORTD_ID:
			PORTD = Copy_u8Value;
			break;
		default :
			break ;
		}
}
u8 MDIO_voidGetPortValue (u8 Copy_u8PortName)
{
	u8 Local_u8PortValue;
	switch (Copy_u8PortName)
		{
		case PORTA_ID:
			Local_u8PortValue = PORTA;
			break;
		case PORTB_ID:
			Local_u8PortValue = PORTB;
			break ;
		case PORTC_ID:
			Local_u8PortValue = PORTC;
			break;
		case PORTD_ID:
			Local_u8PortValue = PORTD;
			break;
		default :
			break ;
		}
	return Local_u8PortValue ;
}
