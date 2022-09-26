/*
 * EXT_INTERRUPTS_REGISTERS.h
 *
 * Created: 8/21/2022 12:40:29 AM
 *  Author: Administrator
 */ 

/************************************************************************/
/*                    External Interrupts Registers                     */
/************************************************************************/

#ifndef EXT_INTERRUPTS_REGISTERS_H_
#define EXT_INTERRUPTS_REGISTERS_H_

// External Interrupts
#define SREG    (*( (volatile uint8_t*) 0x5F) )
#define MCUCR   (*( (volatile uint8_t*) 0x55) )
#define MCUCSR  (*( (volatile uint8_t*) 0x54) )
#define GICR    (*( (volatile uint8_t*) 0x5B) )
#define GIFR    (*( (volatile uint8_t*) 0x5A) )

#endif /* EXT_INTERRUPTS_REGISTERS_H_ */