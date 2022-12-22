/*
 * GIE_Program.c
 *
 *  
 *      Author: NOUR ALAA ELDIN HANAFY MOHARRAM
 */
#include"../../common/Bit_wise.h"
#include"../../common/Typedefs.h"
#include"GIE_Interface.h"
#include "GIE_Register.h"
/*Global interrupt enable function by setting the SREG_I bit*/
void GIE_voidEnable(void)
{
	//Enable GIE for External interrupt
	SET_BIT(SREG,SREG_I);
}
/*Global interrupt disable function by setting the SREG_I bit*/

void GIE_voidDisable(void)
{
	//Disable GIE for external Interrupt
	CLR_BIT(SREG,SREG_I);
}
