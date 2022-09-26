/*
 * TIMER_REGISTERS.h
 *
 * Created: 8/21/2022 2:46:19 AM
 *  Author: Administrator
 */ 


#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

#include "../../LIB/STD_TYPES.h"
#include <math.h>

#define NUMBITS 8 // no. of bits in the Timer Register
#define SIZEBITS pow(2, NUMBITS) // Total size of the register

// Timer Related Registers
#define OCR0  (*(volatile uint8_t*)0x5C)
#define TIFR  (*(volatile uint8_t*)0x58)

// Timer0 Registers
#define TCCR0 (*(volatile uint8_t*)0x53)
#define TCNT0 (*(volatile uint8_t*)0x52)

// Timer1 (A, B, H, L) Registers
#define TCCR1B (*(volatile uint8_t*)0x4E)
#define TCNT1H (*(volatile uint8_t*)0x4D)
#define TCNT1L (*(volatile uint8_t*)0x4C)

// Timer2 Registers
#define TCCR2 (*(volatile uint8_t*)0x45)
#define TCNT2 (*(volatile uint8_t*)0x44)

#endif /* TIMER_REGISTERS_H_ */