/*
 * BIT_MATH.h
 *
 * Created: 8/21/2022 2:03:08 AM
 *  Author: Administrator
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR, BITNUMBER) (VAR) |=  (1 << (BITNUMBER))
#define CLR_BIT(VAR, BITNUMBER) (VAR) &= ~(1 << (BITNUMBER))
#define TOG_BIT(VAR, BITNUMBER) (VAR) ^=  (1 << (BITNUMBER)) //XOR
#define GET_BIT(VAR, BITNUMBER) (((VAR) >> (BITNUMBER)) & 0x01)
// DUNNO WHATS A GET_BIT --> 

// Direction Defines
#define IN	  0
#define OUT   1

// Value Defines
#define LOW   0
#define HIGH  1

#endif /* BIT_MATH_H_ */