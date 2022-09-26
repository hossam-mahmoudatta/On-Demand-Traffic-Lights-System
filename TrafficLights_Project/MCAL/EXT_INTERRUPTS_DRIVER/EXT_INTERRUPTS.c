/*
 * EXT_INTERRUPTS.c
 *
 * Created: 8/21/2022 12:37:04 AM
 *  Author: Administrator
 */

/************************************************************************/
/*               External Interrupts Function Declarations              */
/************************************************************************/

#include "EXT_INTERRUPTS.h"


// Initialize External Interrupt
void EXT_INTERRUPT_Init(void) {
	// Clearing the ISCXX Bits of MCUCR
	CLR_BIT(MCUCR, PIN_0);
	CLR_BIT(MCUCR, PIN_1);
	CLR_BIT(MCUCR, PIN_2);
	CLR_BIT(MCUCR, PIN_3);
	
	// Clearing the ISCXX Bits of MCUCR
	CLR_BIT(MCUCSR, PIN_6);
	
// Initializing the ISC00,ISC01 Bits in INT0 for MCUCR
#if		EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Low_Level
	MCUCR |= EXT_INTERRUPT_Low_Level		;
#elif	EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Logical_Change
	MCUCR |= EXT_INTERRUPT_Logical_Change	;
#elif	EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Falling_Edge
	MCUCR |= EXT_INTERRUPT_Falling_Edge		;
#elif	EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Rising_Edge
	MCUCR |= EXT_INTERRUPT_Rising_Edge		;
#endif

// Initializing the ISC10,ISC11 Bits in INT1 for MCUCR
#if		EXT_INTERRUPT_1_MODE == EXT_INTERRUPT_Low_Level
	(MCUCR |= EXT_INTERRUPT_Low_Level << 2)		;
#elif	EXT_INTERRUPT_1_MODE == EXT_INTERRUPT_Logical_Change
	(MCUCR |= EXT_INTERRUPT_Logical_Change << 2);
#elif	EXT_INTERRUPT_1_MODE == EXT_INTERRUPT_Falling_Edge
	(MCUCR |= EXT_INTERRUPT_Falling_Edge << 2)	;
#elif	EXT_INTERRUPT_1_MODE == EXT_INTERRUPT_Rising_Edge
	(MCUCR |= EXT_INTERRUPT_Rising_Edge << 2)	;
#endif

// Initializing the ISC2 Bit in INT2 for MCUCSR
#if		EXT_INTERRUPT_2_MODE == EXT_INTERRUPT_INT2_Falling_Edge
	CLR_BIT(MCUCSR, PIN_6)	;
#elif	EXT_INTERRUPT_2_MODE == EXT_INTERRUPT_INT2_Rising_Edge
	SET_BIT(MCUCSR, PIN_6)	;
#endif


// Initializing INT0 Bit in GICR
#if		EXT_INTERRUPT_INT0_INIT_STATE == EXT_INTERRUPT_Disable_State
	CLR_BIT(GICR, PIN_6)	;
#elif	EXT_INTERRUPT_INT0_INIT_STATE == EXT_INTERRUPT_Enable_State
	SET_BIT(GICR, PIN_6)	;
#endif

// Initializing INT1 Bit in GICR
#if		EXT_INTERRUPT_INT1_INIT_STATE == EXT_INTERRUPT_Disable_State
	CLR_BIT(GICR, PIN_7)	;
#elif	EXT_INTERRUPT_INT1_INIT_STATE == EXT_INTERRUPT_Enable_State
	SET_BIT(GICR, PIN_7)	;
#endif

// Initializing INT2 Bit in GICR
#if		EXT_INTERRUPT_INT2_INIT_STATE == EXT_INTERRUPT_Disable_State
	CLR_BIT(GICR, PIN_5)	;
#elif	EXT_INTERRUPT_INT2_INIT_STATE == EXT_INTERRUPT_Enable_State
	SET_BIT(GICR, PIN_5)	;
#endif

	// Initializing Interrupt Flags GIFR by setting a '1' to them
	SET_BIT(GIFR, PIN_6)	;
	SET_BIT(GICR, PIN_7)	;
	SET_BIT(GICR, PIN_5)	;
}

// Disable External Interrupt 0 ISR
void EXT_INTERRUPT_Disable_INT0(void) {
	
	// Disabling External Interrupt 0 by clearing PIN6 in GICR
	CLR_BIT(GICR, PIN_6);
}

// Enable External Interrupt 0 ISR
void EXT_INTERRUPT_Enable_INT0(void) {
	// Enabling External Interrupt 0 by setting PIN6 in GICR
	SET_BIT(GICR, PIN_6);
}

// Disable External Global Interrupt
void EXT_INTERRUPT_DisableGlobalInterrupt(void) {
	// Disabling External Interrupt 0 by clearing PIN7 in SREG
	CLR_BIT(SREG, PIN_7);
}

// Enable External Global Interrupt
void EXT_INTERRUPT_EnableGlobalInterrupt(void) {
	// Enabling External Interrupt 0 by setting PIN7 in SREG
	SET_BIT(SREG, PIN_7);
}

// We'll add for the other INTs but later


//The function that will be called in the EXT INT
void (*CallBackPtr) (void) = NULL;

// External Interrupt Call Back Function
void EXT_INTERRUPT_SetCallBack(void (*CopyFuncPtr) (void)) {
	CallBackPtr = CopyFuncPtr;
}


void __vector_1(void) __attribute__((signal, used));
// Previous prototype __attribute__((signal, used));
// is to tell the compiler that I will use this function
// but not now, so don't optimize and delete it.

void __vector_1(void) {
	if(CallBackPtr != NULL) {
		CallBackPtr();	
	}
}