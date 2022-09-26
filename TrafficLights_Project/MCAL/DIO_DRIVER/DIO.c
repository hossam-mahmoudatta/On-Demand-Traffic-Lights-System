/*
 * dio.c
 * Created: 8/11/2022 2:09:40 PM
 * Author: TESTER
 */ 

/******************************************************************/
/*                            DIO C File                          */
/******************************************************************/

// #include .h
// Global variables
// Function Definitions

#include "DIO.h"

uint8_t DIO_VERIFER = NULL;

EN_DIO_Error_t DIO_Init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction) {
	
	// Initializes the DIO DDRx either to INPUT or OUTPUT
	// 1st Step: Checks if the Pin Number falls b/w 0 and 7
	// 2nd Step: Checks if direction is valid
	// 3rd step: Gets Port Number, if direction is IN  -> CLEARS Bit
	// 4th step: Gets Port Number, if direction is OUT -> SETS Bit
	
	if( (pinNumber < 0) || (pinNumber > 7) ) {
		DIO_VERIFER = DIO_WRONG_PIN_NUMBER;
	}
	else if( (direction != IN) && (direction != OUT) ) {
		DIO_VERIFER = DIO_WRONG_DIRECTION;
	}
	else {
		switch(portNumber) {
			case PORT_A:
				if(direction == IN) {
					CLR_BIT(DDRA, pinNumber);
				}
				else if(direction == OUT) {
					SET_BIT(DDRA, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_B:
				if(direction == IN) {
					CLR_BIT(DDRB, pinNumber);
				}
				else if(direction == OUT) {
					SET_BIT(DDRB, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_C:
				if(direction == IN) {
					CLR_BIT(DDRC, pinNumber);
				}
				else if(direction == OUT) {
					SET_BIT(DDRC, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_D:
				if(direction == IN) {
					CLR_BIT(DDRD, pinNumber);
				}
				else if(direction == OUT) {
					SET_BIT(DDRD, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			default:
				DIO_VERIFER = DIO_WRONG_PORT_NUMBER;
			break;
		}
	}
	return DIO_VERIFER;
}

EN_DIO_Error_t DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t value) {
	
	// Initializes the DIO PORTx either to LOW or HIGH
	// 1st Step: Checks if the Pin Number falls b/w 0 and 7
	// 2nd Step: Checks if value is valid
	// 3rd step: Gets Port Number, if value is LOW  -> CLEARS Bit
	// 4th step: Gets Port Number, if value is HIGH -> SETS Bit
	
	if( (pinNumber < 0) || (pinNumber > 7) ) {
		DIO_VERIFER = DIO_WRONG_PIN_NUMBER;
	}
	else if( (value != IN) && (value != OUT) ) {
		DIO_VERIFER = DIO_WRONG_DIRECTION;
	}
	else {
		switch(portNumber) {
		
			case PORT_A:
				if(value == LOW) {
					CLR_BIT(PORTA, pinNumber);
				}
				else if(value == HIGH) {
					SET_BIT(PORTA, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_B:
				if(value == LOW) {
					CLR_BIT(PORTB, pinNumber);
				}
				else if(value == HIGH) {
					SET_BIT(PORTB, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_C:
				if(value == LOW) {
					CLR_BIT(PORTC, pinNumber);
				}
				else if(value == HIGH) {
					SET_BIT(PORTC, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_D:
				if(value == LOW) {
					CLR_BIT(PORTD, pinNumber);
				}
				else if(value == HIGH) {
					SET_BIT(PORTD, pinNumber);
				}
				DIO_VERIFER = DIO_OK;
			break;
		
			default:
				DIO_VERIFER = DIO_WRONG_PORT_NUMBER;
			break;
		}
	}
	
	return DIO_VERIFER;
}

EN_DIO_Error_t DIO_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value) {
	
	// Reads the DIO
	// 1st Step: Checks if the Pin Number falls b/w 0 and 7
	// 2nd step: Gets the status of the PIN, and saves it into 'value'
	
	if( (pinNumber < 0) || (pinNumber > 7) ) {
		DIO_VERIFER = DIO_WRONG_PIN_NUMBER;
	}
	else {	
		switch(portNumber) {
		
			case PORT_A:
				*value = (PINA & (1 << pinNumber)) >> pinNumber;
			
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_B:
				*value = (PINB & (1 << pinNumber)) >> pinNumber;
			
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_C:
				*value = (PINC & (1 << pinNumber)) >> pinNumber;
			
				DIO_VERIFER = DIO_OK;
			break;
		
			case PORT_D:
				*value = (PIND & (1 << pinNumber)) >> pinNumber;
			
				DIO_VERIFER = DIO_OK;
			break;
		
			default:
				DIO_VERIFER = DIO_WRONG_PORT_NUMBER;
			break;
		}
	}
	return DIO_VERIFER;
}

EN_DIO_Error_t DIO_Toggle(uint8_t pinNumber, uint8_t portNumber) {
	
	// Initializes the DIO to TOGGLE
	// 1st Step: Checks if the Pin Number falls b/w 0 and 7
	// 2nd Step: Gets Port Number, TOGGLES Pin
	
	if( (pinNumber < 0) || (pinNumber > 7) ) {
		DIO_VERIFER = DIO_WRONG_PIN_NUMBER;
	}
	else {
		switch(portNumber) {
			
			case PORT_A:
			TOG_BIT(PORTA, pinNumber);
			
			DIO_VERIFER = DIO_OK;
			break;
			
			case PORT_B:
			TOG_BIT(PORTB, pinNumber);
			
			DIO_VERIFER = DIO_OK;
			break;
			
			case PORT_C:
			TOG_BIT(PORTC, pinNumber);
			
			DIO_VERIFER = DIO_OK;
			break;
			
			case PORT_D:
			TOG_BIT(PORTD, pinNumber);
			
			DIO_VERIFER = DIO_OK;
			break;
			
			default:
			DIO_VERIFER = DIO_WRONG_PORT_NUMBER;
			break;
		}
	}
	
	return DIO_VERIFER;
}

// Toggle DIO