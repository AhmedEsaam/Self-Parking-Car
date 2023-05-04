
/**
 * @file APP_Main.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief :
 * @version 1.0 main updated
 * @date 2023-05-04
 * @compiler GNU GCC
 * @copyright Copyright (c) 2023
 *
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include  <util/delay.h>

#include "../HAL/LCD/LCD_int.h"

#if 1
// Name animation
void main(void)
{
	HLCD_voidInit();
	while(1)
	{
		HLCD_voidGoToXY(1,0);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,0);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,4);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(1,4);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(1,8);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,8);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(0,12);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

		HLCD_voidGoToXY(1,12);
		HLCD_voidSendString("Doaa");
		_delay_ms(1000);
		HLCD_voidClearDisplay();

	}
}
#endif
