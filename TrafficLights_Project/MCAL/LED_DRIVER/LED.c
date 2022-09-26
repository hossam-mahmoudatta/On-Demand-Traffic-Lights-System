/*
 * led.c
 * Created: 8/11/2022 6:34:31 PM
 *  Author: Administrator
 */

/******************************************************************/
/*                            LED C File                          */
/******************************************************************/

#include "LED.h"

uint8_t LED_VERIFER = NULL;

EN_LED_Error_t LED_Init(uint8_t ledPin, uint8_t ledPort) {
	
	// Initializes the LED
	// The checks here is for the return value
	// The LED Init depends on the DIO Init
	
	if ( DIO_Init(ledPin, ledPort, OUT) == DIO_OK ) {
		//DIO_Init(ledPin, ledPort, OUT);
		LED_VERIFER = LED_OK;
	}
	else if ( DIO_Init(ledPin, ledPort, OUT) == DIO_WRONG_PIN_NUMBER ) {
		LED_VERIFER = LED_WRONG_PIN_NUMBER;
	}
	else if ( DIO_Init(ledPin, ledPort, OUT) == DIO_WRONG_PORT_NUMBER ) {
		LED_VERIFER = LED_WRONG_PORT_NUMBER;
	}
	else if ( DIO_Init(ledPin, ledPort, OUT) == DIO_WRONG_DIRECTION ) {
		LED_VERIFER = LED_WRONG_DIRECTION;
	}
	return LED_VERIFER;
}
// Initializes LED

EN_LED_Error_t LED_On(uint8_t ledPin, uint8_t ledPort) {
	
	// Initializes the LED and sets the Pin to ON
	// The checks here is for the return value
	
	if ( DIO_Write(ledPin, ledPort, HIGH) == DIO_OK ) {
		//DIO_Write(ledPin, ledPort, HIGH);
		LED_VERIFER = LED_OK;
	}
	else if ( DIO_Write(ledPin, ledPort, HIGH) == DIO_WRONG_PIN_NUMBER ) {
		LED_VERIFER = LED_WRONG_PIN_NUMBER;
	}
	else if ( DIO_Write(ledPin, ledPort, HIGH) == DIO_WRONG_PORT_NUMBER ) {
		LED_VERIFER = LED_WRONG_PORT_NUMBER;
	}
	else if ( DIO_Write(ledPin, ledPort, HIGH) == DIO_WRONG_DIRECTION ) {
		LED_VERIFER = LED_WRONG_DIRECTION;
	}
	return LED_VERIFER;
}
// Turning LED On

EN_LED_Error_t LED_Off(uint8_t ledPin, uint8_t ledPort) {
	
	// Initializes the LED and sets the Pin to OFF
	// The checks here is for the return value
	
	if ( DIO_Write(ledPin, ledPort, LOW) == DIO_OK ) {
		//DIO_Write(ledPin, ledPort, LOW);
		LED_VERIFER = LED_OK;
	}
	else if ( DIO_Write(ledPin, ledPort, LOW) == DIO_WRONG_PIN_NUMBER ) {
		LED_VERIFER = LED_WRONG_PIN_NUMBER;
	}
	else if ( DIO_Write(ledPin, ledPort, LOW) == DIO_WRONG_PORT_NUMBER ) {
		LED_VERIFER = LED_WRONG_PORT_NUMBER;
	}
	else if ( DIO_Write(ledPin, ledPort, LOW) == DIO_WRONG_DIRECTION ) {
		LED_VERIFER = LED_WRONG_DIRECTION;
	}
	return LED_VERIFER;
}
// Turning LED Off

EN_LED_Error_t LED_Toggle(uint8_t ledPin, uint8_t ledPort) {
	
	// Initializes the LED and sets the Pin for TOGGLING Mode
	// The checks here is for the return value
	
	if ( DIO_Toggle(ledPin, ledPort) == DIO_OK ) {
		//DIO_Toggle(ledPin, ledPort);
		LED_VERIFER = LED_OK;
	}
	else if ( DIO_Toggle(ledPin, ledPort) == DIO_WRONG_PIN_NUMBER ) {
		LED_VERIFER = LED_WRONG_PIN_NUMBER;
	}
	else if ( DIO_Toggle(ledPin, ledPort) == DIO_WRONG_PORT_NUMBER ) {
		LED_VERIFER = LED_WRONG_PORT_NUMBER;
	}
	return LED_VERIFER;
}
// Toggling LED
