/*
 * GIE_prog.c
 *
 *  Created on: Apr 14, 2023
 *      Author: doaah
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GIE_priv.h"
#include "GIE_config.h"
#include "GIE_int.h"

void M_GIE_void_enable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}
void M_GIE_void_disable(void)
{
	 CLR_BIT(SREG_REG,I_BIT);
}
