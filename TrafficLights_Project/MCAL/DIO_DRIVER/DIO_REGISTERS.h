/*
 * DIO_REGISTERS.h
 * Created: 8/21/2022 2:19:20 AM
 * Author: Administrator
 */ 

/************************************************************************/
/*                             DIO Registers                            */
/************************************************************************/

#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#include "../../LIB/STD_TYPES.h"

// PORTA Registers
#define PORTA (*(volatile uint8_t*)0x3B)
#define DDRA  (*(volatile uint8_t*)0x3A)
#define PINA  (*(volatile uint8_t*)0x39)
// since this was a pure address, I had to cast it
// then dereference it so that i can access its pointed value.

// PORTB Registers
#define PORTB (*(volatile uint8_t*)0x38)
#define DDRB  (*(volatile uint8_t*)0x37)
#define PINB  (*(volatile uint8_t*)0x36)

// PORTC Registers
#define PORTC (*(volatile uint8_t*)0x35)
#define DDRC  (*(volatile uint8_t*)0x34)
#define PINC  (*(volatile uint8_t*)0x33)

// PORTD Registers
#define PORTD (*(volatile uint8_t*)0x32)
#define DDRD  (*(volatile uint8_t*)0x31)
#define PIND  (*(volatile uint8_t*)0x30)

#endif /* DIO_REGISTERS_H_ */