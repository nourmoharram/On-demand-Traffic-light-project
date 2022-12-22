/*
 * Traffic_light_project.c
 *
 * Author : NOUR ALAA ELDIN HANAFY MOHARRAM
 */ 

#include"APPLICATION/Application.h"

int main(void)
{
	/*App initialization for timer,interrupt,button,leds and call back function*/
	APP_INIT();


    while (1) 
    {
		/*Start Normal mode*/
		APP_START();
		
    }
}

