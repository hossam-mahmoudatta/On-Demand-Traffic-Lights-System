/*
 * EXT_INTERRUPTS_CONFIG.h
 *
 * Created: 8/21/2022 1:17:29 AM
 *  Author: Administrator
 */ 

/************************************************************************/
/*              External Interrupts Typedefs Configurations             */
/************************************************************************/

#ifndef EXT_INTERRUPTS_CONFIG_H_
#define EXT_INTERRUPTS_CONFIG_H_


#define EXT_INTERRUPT_0_MODE	EXT_INTERRUPT_Rising_Edge
/* Configure range of commands to use for INTERRUPT 0 Mode
 *	Macros Available:
 *	
 *	EXT_INTERRUPT_Low_Level
 *	EXT_INTERRUPT_Logical_Change
 *	EXT_INTERRUPT_Falling_Edge
 *	EXT_INTERRUPT_Rising_Edge
 *
 */


#define EXT_INTERRUPT_1_MODE	EXT_INTERRUPT_Falling_Edge
/* Configure range of commands to use for INTERRUPT 1 Mode
 *	Macros Available:
 *	
 *	EXT_INTERRUPT_Low_Level
 *	EXT_INTERRUPT_Logical_Change
 *	EXT_INTERRUPT_Falling_Edge
 *	EXT_INTERRUPT_Rising_Edge
 *
 */


#define EXT_INTERRUPT_2_MODE	EXT_INTERRUPT_Falling_Edge
/* Configure range of commands to use for INTERRUPT 2 Mode
 *	Macros Available:
 *	
 *	EXT_INTERRUPT_INT2_Falling_Edge	
 *	EXT_INTERRUPT_INT2_Rising_Edge
 *
 */


#define EXT_INTERRUPT_INT0_INIT_STATE	EXT_INTERRUPT_Enable_State
#define EXT_INTERRUPT_INT1_INIT_STATE	EXT_INTERRUPT_Enable_State
#define EXT_INTERRUPT_INT2_INIT_STATE	EXT_INTERRUPT_Disable_State
/* Configure range of commands to use for GICR INTERRUPT Initial State
 *	Macros Available:
 *	
 *	EXT_INTERRUPT_Disable_State
 *	EXT_INTERRUPT_Enable_State
 *
 */


#endif /* EXT_INTERRUPTS_CONFIG_H_ */