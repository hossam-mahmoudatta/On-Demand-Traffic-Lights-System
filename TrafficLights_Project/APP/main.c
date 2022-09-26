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
#include "TRAFFIC_LAB.h"
#include "UNIT_TEST_LAB.h"

float Time_Delay = 5;

int main(void) {
	
	// Initialization for the Testing LEDs
	TestLEDS_Init();
	
	// Initialization for the Traffic Lights LEDs and External Interrupts
	TrafficLights_Init();
	TrafficLights_InterruptInit();
	
	while(1) {
		
		TrafficLights_NormalMode(Time_Delay);
		
		// Unit Tests
		//Testing_LED_DRIVER(PIN_5, 'G');
		//Testing_TIMER_DRIVER(PRESCALER_1024, NULL);
		
	}
}
