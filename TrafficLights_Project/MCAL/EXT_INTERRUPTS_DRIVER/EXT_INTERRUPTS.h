/*
 * interrupt.h
 *
 * Created: 8/20/2022 10:34:02 PM
 *  Author: Administrator
 */ 

/************************************************************************/
/*                External Interrupts Functions Prototypes              */
/************************************************************************/

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO_DRIVER/DIO_TYPES.h"
#include "EXT_INTERRUPTS_CONFIG.h"
#include "EXT_INTERRUPTS_REGISTERS.h"
#include "EXT_INTERRUPTS_TYPES.h"

// Initialize External Interrupt
void EXT_INTERRUPT_Init(void);

// Disable External Interrupt 0 ISR
void EXT_INTERRUPT_Disable_INT0(void);

// Enable External Interrupt 0 ISR
void EXT_INTERRUPT_Enable_INT0(void);

// Disable External Global Interrupt
void EXT_INTERRUPT_DisableGlobalInterrupt(void);

// Enable External Global Interrupt
void EXT_INTERRUPT_EnableGlobalInterrupt(void);

// We'll add for the other INTs but later


//The function that will be called in the EXT INT
void (*CallBackPtr) (void);

// External Interrupt Call Back Function
void EXT_INTERRUPT_SetCallBack(void (*CopyFuncPtr) (void));

//
void __vector_1(void);


//void vector (void) __attribute__ ((signal, __INTR_ATTRS)) __VA_ARGS__;
//void INT0_vect (void) {}

/*
ISR (INT0_vect) {
	if(LedNumber < NUMBER_OF_LEDS) {
		LedNumber++;
	}
	else {
		LedNumber = 0;
	}
}
*/

#endif /* EXT_INTERRUPT_H_ */