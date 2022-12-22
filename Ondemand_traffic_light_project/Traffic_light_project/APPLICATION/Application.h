/*
 * Application.h
 *
 *  Author: NOUR ALAA ELDEN HANAFY MOHARRAM
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include"../common/Bit_wise.h"
#include"../common/Typedefs.h"
#include"../HAL/Button/Button.h"
#include"../HAL/LED/LED.h"
void APP_INIT(void);

void NORMAL_MODE(void);

void PEDESTRIAN_MODE(void);

void CLOSE_MODE(void);

void APP_START(void);

void Mode_1(void);

void Mode_2(void);

#endif /* APPLICATION_H_ */