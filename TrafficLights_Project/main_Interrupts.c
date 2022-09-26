/*
 * ATMega32_Interrupts.c
 *
 * Created: 8/17/2022 1:48:30 AM
 * Author : Administrator
 */

/******************************************************************/
/*                Using Interrupts with ATMega32A                 */
/******************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

#define NUMBER_OF_LEDS 4

uint8_t LedNumber = 0;

int main(void)
{
    /* Replace with your application code */
	
    // 1. Set Direction for Button PIN to INPUT
	DDRD |= (1 << PIND2);
	
	// 2. Set Direction for LEDS PIN to OUTPUT
	DDRA |= (1 << PINA0);
	DDRA |= (1 << PINA3);
	DDRA |= (1 << PINA6);
	
	// 3. Enable Global Interrupts - Setting Bit7 in the Status Register to 1
	sei();
	
	// 4. Choose the External Interrupt Sense: Sense on Rising Edge
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	
	// 5. Enable External Interrupt 0: INT0
	GICR |= (1 << INT0);
	
	while (1) {
		switch (LedNumber) {
			case 0:
				// Turn all LEDs Off
				PORTA &= ~(1 << PORTA0);
				PORTA &= ~(1 << PORTA3);
				PORTA &= ~(1 << PORTA6);
			break;
			
			case 1:
				// Turn on LED1 - Set Pin to HIGH
				PORTA |= (1 << PORTA0);
			break;
			
			case 2:
				// Turn on LED2 - Set Pin to HIGH
				PORTA |= (1 << PORTA3);
			break;
			
			case 3:
				// Turn on LED3 - Set Pin to HIGH
				PORTA |= (1 << PORTA6);
			break;
			
			default:
				// Do Nothing
			break;
		}
    }
}


//void vector (void) __attribute__ ((signal, __INTR_ATTRS)) __VA_ARGS__;
//void INT0_vect (void) {}

ISR (INT0_vect) {
	if(LedNumber < NUMBER_OF_LEDS) {
		LedNumber++;
	}
	else {
		LedNumber = 0;
	}
}

