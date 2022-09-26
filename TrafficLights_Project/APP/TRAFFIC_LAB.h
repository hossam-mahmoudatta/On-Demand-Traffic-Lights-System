/*
 * TRAFFIC_HEADER.h
 *
 * Created: 8/23/2022 10:42:30 AM
 *  Author: TESTER
 */ 


#ifndef TRAFFIC_HEADER_H_
#define TRAFFIC_HEADER_H_

//#include <util/delay.h>
#include "../MCAL/DIO_DRIVER/DIO.h"
#include "../MCAL/LED_DRIVER/LED.h"
#include "../MCAL/TIMER_DRIVER/TIMER.h"
#include "../MCAL/EXT_INTERRUPTS_DRIVER/EXT_INTERRUPTS.h"

void EXT_INTERRUPT_INT0_ISR(void);

void TrafficLights_Init(void);

void TrafficLights_InterruptInit(void);

void TrafficLights_NormalMode(float delay);

void TrafficLights_TrafficOff(void);

void TrafficLights_TrafficGreen(float delay);

void TrafficLights_BlinkingYellow(void);

void TrafficLights_PedBlinkingYellow(void);

void TrafficLights_TrafficRed(float delay);

void TrafficLights_PedestrianMode1(float delay);

void TrafficLights_PedestrianMode2(void);


#endif /* TRAFFIC_HEADER_H_ */