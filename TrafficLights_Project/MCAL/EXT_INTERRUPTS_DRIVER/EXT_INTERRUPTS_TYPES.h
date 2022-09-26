/*
 * EXT_INTERRUPTS_TYPES.h
 *
 * Created: 8/21/2022 12:49:24 AM
 *  Author: Administrator
 */ 

/************************************************************************/
/*                 External Interrupts Typedefs & Macros                */
/************************************************************************/

#ifndef EXT_INTERRUPTS_TYPES_H_
#define EXT_INTERRUPTS_TYPES_H_


// Defining the ISCXX Bits 0-3 in INT0, INT1 for the MCUCR
#define EXT_INTERRUPT_Low_Level				0
#define EXT_INTERRUPT_Logical_Change		1
#define EXT_INTERRUPT_Falling_Edge			2
#define EXT_INTERRUPT_Rising_Edge			3

// Defining the ISC2 Bit6 in INT2 for the MCUCSR
#define EXT_INTERRUPT_INT2_Falling_Edge		0
#define EXT_INTERRUPT_INT2_Rising_Edge		1

// Defining Bits 5-7 in the GICR
#define EXT_INTERRUPT_Disable_State			0
#define EXT_INTERRUPT_Enable_State			1


#endif /* EXT_INTERRUPTS_TYPES_H_ */