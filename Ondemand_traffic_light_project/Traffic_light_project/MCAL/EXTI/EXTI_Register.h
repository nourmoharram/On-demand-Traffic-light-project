/*
 * EXTI_Register.h
 *
 *      Author: NOUR ALAA ELDIN HANAFY MOHARRAM
 */

#ifndef MCAL_EXTI_EXTI_HEADER_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_HEADER_EXTI_REGISTER_H_

#define GICR           *((volatile u8*)0x5B)
#define GICR_INT1       7
#define GICR_INT0       6
#define GICR_INT2       5

#define GIFR           *((volatile u8*)0x5A)

#define MCUCR          *((volatile u8*)0x55)
#define MCUCR_ISC11      3
#define MCUCR_ISC10      2
#define MCUCR_ISC01      1
#define MCUCR_ISC00      0

#define MCUSR          *((volatile u8*)0x54)
#define MCUSR_INT2       6
#endif /* MCAL_EXTI_EXTI_HEADER_EXTI_REGISTER_H_ */
