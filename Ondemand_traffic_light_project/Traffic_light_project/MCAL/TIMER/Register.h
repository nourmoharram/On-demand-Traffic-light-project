/*
 * Register.h
 *
 * 
 *  Author: NOUR ALAA ELDIN MOHARRAM
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_


#define TCCR0           *((volatile u8*)0x53) //TIMER 0 CONTROL REGISTER
#define TCCR0_WGM00     6                    // Wave form generation mode bit0
#define TCCR0_WGM01     3                    //wave form generation mode bit1
#define TCCR0_CS02      2                    // prescaller bit2
#define TCCR0_CS01      1                    // prescaller bit1
#define TCCR0_CS00      0                    // prescaller bit0
#define TCCR0_COM00     4
#define TCCR0_COM01     5
#define OCR0           *((volatile u8*)0x5c) //output compare register 0

#define TIMSK          *((volatile u8*)0x59)  // timer mask interrupt
#define TIMSK_OCIE0    1                      //output compare interrupt enable
#define TIMSK_TOIE0    0
#define TIFR           *((volatile u8*)0x58)  // Interrupt flag register
#define TIFR_TOV0      0

#define TCNT0		 *((volatile u8*)0x52) //Timer counter

#endif /* REGISTER_H_ */