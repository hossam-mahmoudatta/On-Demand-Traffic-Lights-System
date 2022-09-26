/*
 * TRAFFIC_LAB.c
 *
 * Created: 8/23/2022 10:42:53 AM
 *  Author: TESTER
 */ 

/******************************************************************/
/*             Traffic Program Ready Functions C File             */
/******************************************************************/

#include "TRAFFIC_LAB.h"

//uint8_t Time_Delay = 5;


void TrafficLights_Init() {
	
	// Initializing the Traffic Lights
	// Setting direction of PIN0, PIN1, PIN2 in PORTA to OUTPUT
	LED_Init(PIN_0, PORT_A);
	LED_Init(PIN_1, PORT_A);
	LED_Init(PIN_2, PORT_A);
	
	// Setting direction of PIN0, PIN1, PIN2 in PORTB to OUTPUT
	LED_Init(PIN_0, PORT_B);
	LED_Init(PIN_1, PORT_B);
	LED_Init(PIN_2, PORT_B);
	
	// Initializing The Timer0 in Normal Mode with Prescaler 1024
	TIMER_Init(PRESCALER_1024);
}

void TrafficLights_InterruptInit() {
	
	// Combining all Interrupts Initializing functions 
	// into one function that calls them together
	EXT_INTERRUPT_Init();
	EXT_INTERRUPT_SetCallBack(EXT_INTERRUPT_INT0_ISR);
	EXT_INTERRUPT_Enable_INT0();
	EXT_INTERRUPT_EnableGlobalInterrupt();
}



void TrafficLights_NormalMode(float delay) {
	
	// Normal Mode: Car Traffic Lights
	// Green -> Blinking Yellow -> Red -> Blinking Yellow
	TrafficLights_TrafficGreen(delay);
	TrafficLights_BlinkingYellow();
	TrafficLights_TrafficRed(delay);
	TrafficLights_TrafficOff();
	TrafficLights_BlinkingYellow();
}

void TrafficLights_PedestrianMode1(float delay) {
	
	// Pedestrian Mode 1: Pedestrian Traffic Lights
	// if Green == On in Cars :: -> Blinking Yellow -> Red -> Blinking Yellow
	// Then Return to Normal Mode ()
	TrafficLights_TrafficOff();
	TrafficLights_BlinkingYellow();
	TrafficLights_TrafficRed(delay);
	TrafficLights_BlinkingYellow();
}

void TrafficLights_PedestrianMode2() {
	
	// Pedestrian Mode 2: Pedestrian Traffic Lights
	// if Yellow == On in Cars :: -> Blinking Yellow -> Red -> Blinking Yellow
	// Then Return to Normal Mode ()
	//TrafficLights_TrafficOff();
	TrafficLights_PedBlinkingYellow();
}


void TrafficLights_TrafficGreen(float delay) {

	// Toggling PIN2 in PORTA & PIN0 in PORTB to HIGH
		
	LED_On(PIN_2, PORT_A);
	LED_On(PIN_0, PORT_B);
		TIMER_DelaySet(PRESCALER_1024, delay);
		//_delay_ms(5000);
	LED_Off(PIN_2, PORT_A);
	LED_Off(PIN_0, PORT_B);
	
}

void TrafficLights_BlinkingYellow() {
	
	TIMER_Init(PRESCALER_1024);
	
	for (int i = 0 ; i < 9 ; i++) {
		LED_On(PIN_1, PORT_A);
		LED_On(PIN_1, PORT_B);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
		LED_Off(PIN_1, PORT_A);
		LED_Off(PIN_1, PORT_B);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
	}
	
	
	
	/*
	for (int i = 0 ; i < 17 ; i++) {
		LED_Toggle(PIN_1, PORT_A);
		LED_Toggle(PIN_1, PORT_B);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
	}
	*/
}

void TrafficLights_PedBlinkingYellow() {
	
	TIMER_Init(PRESCALER_1024);
	
	for (int i = 0 ; i < 7 ; i++) {
		LED_On(PIN_1, PORT_A);
		LED_On(PIN_1, PORT_B);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
		LED_Off(PIN_1, PORT_A);
		LED_Off(PIN_1, PORT_B);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
			//_delay_ms(500);
	}
	
	
	
	/*
	for (int i = 0 ; i < 17 ; i++) {
		LED_Toggle(PIN_1, PORT_A);
		LED_Toggle(PIN_1, PORT_B);
			TIMER_DelaySet(PRESCALER_1024, 0.5);
	}
	*/
}

void TrafficLights_TrafficRed(float delay) {
	
	LED_On(PIN_0, PORT_A);
	LED_On(PIN_2, PORT_B);
		TIMER_DelaySet(PRESCALER_1024, delay);
		//_delay_ms(5000);
	LED_Off(PIN_0, PORT_A);
	LED_Off(PIN_2, PORT_B);
}

void TrafficLights_TrafficOff(void) {
	
	LED_Off(PIN_0, PORT_A);
	LED_Off(PIN_2, PORT_A);
	LED_Off(PIN_0, PORT_B);
	LED_Off(PIN_2, PORT_B);
}

void EXT_INTERRUPT_INT0_ISR(void) {
	if( GET_BIT(PORTA, 2) ) {
		//PORTA & (1<<2)
		TrafficLights_PedestrianMode1(5);
	}
	else if( GET_BIT(PORTA, 1) && GET_BIT(PORTB, 1) ) {
		//(PORTA & ~(1<<2)) & (PORTA & ~(1<<0))
		//TrafficLights_PedestrianMode2(5);
		TrafficLights_PedestrianMode2();
	}
}