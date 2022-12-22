/*
 * LED.c
 *
 *  Author: NOUR ALAA ELDEN HANAFY MOHARRAM
 */ 
#include"../../common/Bit_wise.h"
#include"../../common/Typedefs.h"
#include"LED.h"
#include"../../MCAL/DIO/DIO_Interface.h"


/*Traffic light LEDS*/
void Car_red_led(u8 Led_Status)
{
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	if(Led_Status == ENABLE_LED)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	}
	else if(Led_Status == DISABLE_LED)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else
	{
		//do nothing
	}
}
void Car_green_led(u8 Led_Status)
{
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	if(Led_Status == ENABLE_LED)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
	}
	else if(Led_Status == DISABLE_LED)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);
	}
	else
	{
		//do nothing
	}
}
void Car_yellow_led(u8 Led_Status)
{
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	if(Led_Status == ENABLE_LED)
	{
		//TOG_BIT(DIO_u8PORTA,DIO_u8PIN1);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);

	}
	else if(Led_Status == DISABLE_LED)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
	}
	else
	{
		//do nothing
	}
}
/*************************************************************/
/*Pedestrian light LEDS*/

void Pedestrian_red_led(u8 Led_Status)
{
	if(Led_Status == ENABLE_LED)
	{
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	}
	else if(Led_Status == DISABLE_LED)
	{
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else
	{
		//do nothing
	}
}
void Pedestrian_green_led(u8 Led_Status)
{
	if(Led_Status == ENABLE_LED)
	{
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
	}
	else if(Led_Status == DISABLE_LED)
	{
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_LOW);
	}
	else
	{
		//do nothing
	}
}
void Pedestrian_yellow_led(u8 Led_Status)
{
	if(Led_Status == ENABLE_LED)
	{
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
		//TOG_BIT(DIO_u8PORTA,DIO_u8PIN5);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);

	}
	else if(Led_Status == DISABLE_LED)
	{
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
	}
	else
	{
		//do nothing
	}
}