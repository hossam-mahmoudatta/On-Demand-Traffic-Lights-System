/*
 * button.h
 *
 * Created: 8/11/2022 10:55:32 PM
 *  Author: Administrator
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../DIO_DRIVER/DIO.h"
#include "../EXT_INTERRUPTS_DRIVER/EXT_INTERRUPTS.h"
#include "../TIMER_DRIVER/TIMER.h"


/*
#define BUTTON_ON_PORT PORT_C
#define BUTTON_ON_PIN PIN0

#define BUTTON_OFF_PORT PORT_D
#define BUTTON_OFF_PIN PIN7
*/

void BUTTON_Init(uint8_t buttonPin, uint8_t buttonPort);

void BUTTON_Read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value);

void BUTTON_State();




#endif /* BUTTON_H_ */