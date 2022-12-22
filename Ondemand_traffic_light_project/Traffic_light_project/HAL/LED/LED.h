/*
 * LED.h
 *
 *  Author: NOUR ALAA ELDEN HANAFY MOHARRAM
 */ 


#ifndef LED_H_
#define LED_H_
/*Traffic light leds for cars*/
void Car_red_led(u8 Led_Status);
void Car_green_led(u8 Led_Status);
void Car_yellow_led(u8 Led_Status);
/*Pedestrian light leds for people*/
void Pedestrian_red_led(u8 Led_Status);
void Pedestrian_green_led(u8 Led_Status);
void Pedestrian_yellow_led(u8 Led_Status);

#endif /* LED_H_ */