/*
 * mainButtons.c
 *
 * Created: 8/19/2022 3:20:25 AM
 *  Author: Administrator
 */ 

/******************************************************************/
/*            Creating Your Own Library: Register File            */
/*                   1. Create Register File                      */
/*                   2. Create Driver Library                     */
/*            Driver Library Consists of .c & .h Files            */
/*                   Main Execution of the App                    */
/******************************************************************/

/*
//#include <avr/io.h>
#include "MCAL/DIO Driver/dio.h"
#include "MCAL/LED Driver/led.h"
#include "MCAL/BUTTON Driver/button.h"

	
	uint8_t Button_1_State;
	uint8_t Button_2_State;
	
	// 1. Setting direction of PIN4 in PORTA to OUTPUT
	//DIO_init(0, PORT_A, OUT);
	//DIO_init(0, PORT_B, OUT);
	LED_init(PIN_0, PORT_A);
	LED_init(PIN_0, PORT_B);

	BUTTON_init(PIN_0, PORT_C);
	BUTTON_init(PIN_7, PORT_D);
	
	while (1) {
		// 2. Setting PIN4 in PORTA to HIGH
		//DIO_write(PIN_0, PORT_A, HIGH);
		//DIO_write(PIN_0, PORT_B, LOW);
		// Nice implementation for the functions
		BUTTON_read(PIN_0, PORT_C, &Button_1_State);
		BUTTON_read(PIN_7, PORT_D, &Button_2_State);
		
		if(Button_1_State == HIGH) {
			LED_on(PIN_0, PORT_A);
			//LED_off(PIN_0, PORT_B);	
		}
		else if(Button_1_State == LOW) {
			LED_off(PIN_0, PORT_A);
		}
		
		if(Button_2_State == HIGH) {
			LED_off(PIN_0, PORT_B);
			//LED_off(PIN_0, PORT_B);
		}
		else if(Button_2_State == LOW) {
			LED_on(PIN_0, PORT_B);
		}	
	}
*/