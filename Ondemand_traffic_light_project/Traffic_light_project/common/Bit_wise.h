/*
 * Bit_wise.h
 *
 *  Author: NOUR ALAA ELDEN HANAFY MOHARRAM
 */ 


#ifndef BIT_WISE_H_
#define BIT_WISE_H_

#define SET_BIT(Register,Bit_No) (Register |=(1<<Bit_No))
#define CLR_BIT(Register,Bit_No) (Register &=(~(1<<Bit_No)))
#define TOG_BIT(Register,Bit_No) (Register ^=(1<<Bit_No))
#define GET_BIT(Register,Bit_No) ((Register>>Bit_No)&0x01)




#endif /* BIT_WISE_H_ */