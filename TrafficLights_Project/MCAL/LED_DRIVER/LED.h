/*
 * led.h
 *
 * Created: 8/11/2022 6:34:40 PM
 *  Author: Administrator
 */ 


#ifndef LED_H_
#define LED_H_

#include "../DIO_DRIVER/DIO.h"
//#include "../TIMER_DRIVER/TIMER.h"
//#include "../EXT_INTERRUPTS_DRIVER/EXT_INTERRUPTS.h"

typedef enum EN_LED_Error_t {
	LED_OK,
	LED_WRONG_PIN_NUMBER,
	LED_WRONG_PORT_NUMBER,
	LED_WRONG_DIRECTION
} EN_LED_Error_t;


EN_LED_Error_t LED_Init(uint8_t ledPin, uint8_t ledPort);
// Initializes DIO Direction

EN_LED_Error_t LED_On(uint8_t ledPin, uint8_t ledPort);
// Write Data to DIO

EN_LED_Error_t LED_Off(uint8_t ledPin, uint8_t ledPort);
// Toggle DIO

EN_LED_Error_t LED_Toggle(uint8_t ledPin, uint8_t ledPort);
// Read DIO



#endif /* LED_H_ */