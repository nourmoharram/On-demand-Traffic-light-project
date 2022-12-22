/*
 * EXTI_Program.c
 *
 *      Author: NOUR ALAA ELDIN HANAFY MOHARRAM
 */


#include"../../common/Bit_wise.h"
#include"../../common/Typedefs.h"
#include"../EXTI/EXTI_Config.h"
#include"../EXTI/EXTI_Interface.h"
#include"../EXTI/EXTI_Register.h" 


/*Create Global pointer to function to hold INT0 ISR Address*/
static void (*EXTI_pvINT0Func)(void)=NULL; //return type-function name - arguments type
/*PRE-building configuration method */
void EXTI_voidINT0Init(void)
{
	/*1- check sense control */

#if INT0_SENSE== LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01;);
#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "wrong INT0_SENSE configuration option"
#endif
	/*Check peripheral interrupt enable initial state */

#if INT0_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLE
	CLR_BIT(GICR_GICR_INI0);
#else
#error "wrong INT0_INITIAL_STATE Configuration option"
#endif

}
/*POST build configuration */
/*
u8 EXTI_u8INT0SetSenseControl(u8 copy_u8sense)

{
	u8 Local_u8ErrorState = OK;
	switch(copy_u8sense)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	default: Local_u8ErrorState=NOK;

	}
	return Local_u8ErrorState;
}
*/
/*Call back function to send the address for the required ISR function to be executed in case of interrupt happened*/
u8 EXTI_u8INT0SetCallBack(void (*Copy_pvINT0Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvINT0Func != NULL)
	{
		EXTI_pvINT0Func=Copy_pvINT0Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_Pointer;
	}

	return Local_u8ErrorStatus;
}

/*ISR OF INT0*/

void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvINT0Func != NULL)
	{
		EXTI_pvINT0Func();
	}
	else
	{
		/*Stop*/
	}
}
