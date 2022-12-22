/*
 * Application.c
 *
 *  Author: NOUR ALAA ELDIN HANAFY MOHARRAM
 */ 
#include"../APPLICATION/Application.h"


/*COUNTER USED for yellow led toggling*/
u8 counter=0;
u8 Global_mode_flag=0; // global flag to determine which mode to be executed when interrupt occurred flag 1 for red led and 2 for green and yellow
/*App initialization for timer and interrupt and button and callback function within it*/
void APP_INIT(void)
{
	Timer_Init();
	GIE_voidEnable();
	EXTI_voidINT0Init();
	BUTTON_Init();
	EXTI_u8INT0SetCallBack(PEDESTRIAN_MODE);


}
/*
Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
*/
void NORMAL_MODE(void)
{
	Global_mode_flag=2;
	Pedestrian_red_led(1);
	/*Enable led =1
	Disable Led =0
	Toggle Led = 2 */
	Car_green_led(1);
	Timer_delay(5);
	Car_green_led(0);
	
	/*yellow led toggling*/
	Car_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Timer_delay(1);
	Car_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Timer_delay(1);
	Car_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Global_mode_flag=1;
	Car_red_led(1);
	Timer_delay(5);
	Car_red_led(0);
	Global_mode_flag=2;
	
	/*yellow led toggling*/
	Car_yellow_led(1);
	Timer_delay(1);   //first second
	Car_yellow_led(0);
	Timer_delay(1);  //2nd second
	Car_yellow_led(1);
	Timer_delay(1);   //third second
	Car_yellow_led(0);
	Timer_delay(1);   //fourth second
	Car_yellow_led(1);
	Timer_delay(1);   //fifth second
	Car_yellow_led(0);
	
}
/*mode 1 if button pressed and car red led is on (global_mode_flag =1)*/
void Mode_1(void)
{
	Pedestrian_red_led(0);
	Pedestrian_green_led(1);
	Car_red_led(1);
	Timer_delay(5);
	Pedestrian_green_led(0);
	Car_red_led(1);
	CLOSE_MODE();
}
/*mode 2 if pressed when car green led on or yellow led is blinking (global_mode_flag =2)*/
void Mode_2(void)
{
	Pedestrian_red_led(1);
	Timer_delay(5);
	Car_green_led(0);
	Pedestrian_red_led(0);
	
	/*yellow led toggling for both cars and pedestrians*/
	Car_yellow_led(1);
	Pedestrian_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Pedestrian_yellow_led(0);
	Timer_delay(1);
	Car_yellow_led(1);
	Pedestrian_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Pedestrian_yellow_led(0);
	Timer_delay(1);
	Car_yellow_led(1);
	Pedestrian_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Pedestrian_yellow_led(0);
	
	Car_red_led(1);
	Pedestrian_green_led(1);
	Timer_delay(5);
	CLOSE_MODE();
}
/*Pedestrian mode when Push button is pressed implementation */
void PEDESTRIAN_MODE(void)
{
	if(Global_mode_flag==1)
	{
		Mode_1();
	}
	else if(Global_mode_flag == 2)
	{
		Mode_2();
	}
	else
	{
		//do nothing
	}
}
/*Mode when Mode1 and Mode2 are totally finished to return to Normal mode safely*/
void CLOSE_MODE(void)
{
	Car_red_led(0);
	Pedestrian_green_led(1);
	
	/*yellow led toggling for both cars and pedestrians*/
	Car_yellow_led(1);
	Pedestrian_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Pedestrian_yellow_led(0);
	Timer_delay(1);
	Car_yellow_led(1);
	Pedestrian_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Pedestrian_yellow_led(0);
	Timer_delay(1);
	Car_yellow_led(1);
	Pedestrian_yellow_led(1);
	Timer_delay(1);
	Car_yellow_led(0);
	Pedestrian_yellow_led(0);
	
	Pedestrian_green_led(0);
	Pedestrian_red_led(1);
	Car_green_led(1);
	NORMAL_MODE();
}
/*calling Normal mode in app start to start program with it*/
void APP_START(void)
{
	NORMAL_MODE();
}
