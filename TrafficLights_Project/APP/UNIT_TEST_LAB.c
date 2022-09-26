/*
* TrafficLights_Project.c
* On Demand Traffic Light Control Final Project
* Created: 8/19/2022 01:15:05 AM
* Author : Hossam Mahmoud
*/

/******************************************************************/
/*                     Running the Main Program                   */
/******************************************************************/


//#include <avr/io.h>
//#include <util/delay.h>
#include "UNIT_TEST_LAB.h"


void TestLEDS_Init() {
	// Initializing The Testing LEDs
	LED_Init(PIN_0, PORT_C);
	LED_Init(PIN_2, PORT_C);
}

void TestSUCCESS_LED() {
	
	TIMER_Init(PRESCALER_1024);
	LED_Toggle(PIN_2, PORT_C);
	TIMER_DelaySet(PRESCALER_1024, 0.5);
	
	/*
	for (int i = 0 ; i < 9 ; i++) {
		LED_On(PIN_2, PORT_C);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
		LED_Off(PIN_2, PORT_C);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
	}
	*/
}

void TestFAIL_LED() {
	
	TIMER_Init(PRESCALER_1024);
	LED_Toggle(PIN_0, PORT_C);
	TIMER_DelaySet(PRESCALER_1024, 0.5);
	
	/*
	for (int i = 0 ; i < 9 ; i++) {
		LED_On(PIN_0, PORT_C);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
		LED_Off(PIN_0, PORT_C);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
	}
	*/
}

void Testing_LED_DRIVER(uint8_t ledPin, uint8_t ledPort) {
	
	//uint16_t LEDTEST = LED_Init(ledPin, ledPort);
	
	if ( LED_Init(ledPin, ledPort) == LED_WRONG_PIN_NUMBER ) {
		TestFAIL_LED();
	}
	else if ( LED_Init(ledPin, ledPort) == LED_WRONG_PORT_NUMBER ) {
		TestFAIL_LED();
	}
	else if ( LED_Init(ledPin, ledPort) == LED_OK ) {
		TestSUCCESS_LED();
	}
	
}

void Testing_TIMER_DRIVER(uint32_t prescaler, float timeDelay) {
	
	//uint16_t TIMERTEST = TIMER_DelaySet(prescaler, timeDelay);
	
	if ( TIMER_DelaySet(prescaler, timeDelay) == TIMER_WRONG_PRESCALER ) {
		TestFAIL_LED();
	}
	else if ( TIMER_DelaySet(prescaler, timeDelay) == TIMER_WRONG_DELAYVALUE ) {
		TestFAIL_LED();
	}
	else if ( TIMER_DelaySet(prescaler, timeDelay) == TIMER_OK ) {
		TestSUCCESS_LED();
	}
}
