/*
 * Button.c
 *
 *  Author: NOUR ALAA ELDEN HANAFY MOHARRAM
 */ 
#include"../../common/Bit_wise.h"
#include"../../common/Typedefs.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../HAL/Button/Button.h"

u8 PIN_VALUE;
/*Initialize pin direction for button*/
void BUTTON_Init(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
}
/*Read button value*/
void BUTTON_READ(void)
{
	DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&PIN_VALUE);
}
