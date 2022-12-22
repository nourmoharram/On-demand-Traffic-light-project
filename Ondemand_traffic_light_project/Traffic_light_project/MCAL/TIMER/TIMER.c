/*
Author : NOUR ALAA ELDIN HANAFY MOHARRAM
*/


#include"../../common/Bit_wise.h"
#include"../../common/Typedefs.h"
#include"Interface.h"
#include"Register.h"
/*Function to select timer mode and set initial value for counter and select prescaller*/
void Timer_Init(void)
{
	/*Select Normal mode for timer0*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/*Set Timer Initial value*/
	TCNT0 = 0x00;
	/*Set PRE-SCALLER To 1024 to  start timer */
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
}
/*function used to set the required delay according to the program process*/
void Timer_delay(u8 delay_time)
{
	u8 Number_of_over_flows=0;
	u8 counter=0;
	if(delay_time == 5)
	{
		/*after calculations for timer max delay and required delay the number of overflows = 20*/
		Number_of_over_flows=20;
		/*start timer*/
		/*the initial value where timer start count at each time in overflows = 255*/
		TCNT0 = 255;
		
		while(counter < Number_of_over_flows)
		{
			while((TIFR & (1<<0))==0)
			{
			/*WAIT FOR FLAG*/
			}
			/*Clear flag by writing one in it*/
			SET_BIT(TIFR,TIFR_TOV0);
			counter++;
		}
	}
	else if(delay_time == 1)
	{
		/*after calculations for timer max delay and required delay the number of overflows = 4*/
		Number_of_over_flows=4;
		/*start timer*/
		/*the initial value where timer start count at each time in overflows = 255*/
		TCNT0 = 255;
		
		while(counter < Number_of_over_flows)
		{
			while((TIFR & (1<<0))==0)
			{
				/*WAIT FOR FLAG*/
			}
			/*Clear flag by writing one in it*/
			SET_BIT(TIFR,TIFR_TOV0);
			counter++;
		}
	}
}
