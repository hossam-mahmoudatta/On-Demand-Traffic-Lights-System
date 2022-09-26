/*
 * button.c
 *
 * Created: 8/11/2022 10:55:41 PM
 *  Author: Administrator
 */ 

/******************************************************************/
/*                          Button C File                         */
/******************************************************************/

#include "BUTTON.h"

void BUTTON_Init(uint8_t buttonPin, uint8_t buttonPort) {
	DIO_Init(buttonPin, buttonPort, IN);
}

void BUTTON_Read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value) {
	DIO_Read(buttonPin, buttonPort, value);
}