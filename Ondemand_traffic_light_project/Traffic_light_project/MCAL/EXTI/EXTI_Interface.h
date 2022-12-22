/*
 * EXTI_Interface.h
 *
 *  
 *      Author: NOUR ALAA ELDIN HANAFY MOHARRAM
 */

#ifndef MCAL_EXTI_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_HEADER_EXTI_INTERFACE_H_

#define LOW_LEVEL      1
#define ON_CHANGE      2
#define FALLING_EDGE   3
#define RISING_EDGE    4

/*functions to set sense control using PRE-build configurations */
void EXTI_voidINT0Init(void);

void EXTI_voidINT1Init(void);

void EXTI_voidINT2Init(void);


/* a function to set the sense control using a post-build configuration
 * input=Copy_u8Sense
 * options=1-LOW_LEVEL
 *         2- ON_CHANGE
 *         3- FALLING_EDGE
 *         4-RISING_EDGE
 * OUTPUTS: ERROR STATES WITH TYPE U8*/

//u8 EXTI_u8INT0SetSenseControl(u8 copy_u8sense);

//u8 EXTI_u8IntEnable(u8 Copy_u8Int);
//u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8INT0SetCallBack(void (*Copy_pvINT0Func)(void));

#endif /* MCAL_EXTI_EXTI_HEADER_EXTI_INTERFACE_H_ */
