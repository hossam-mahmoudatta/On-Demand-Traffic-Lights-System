/*
 * TESTER_LAB.h
 *
 * Created: 9/21/2022 12:39:31 AM
 *  Author: Administrator
 */ 


#ifndef UNIT_TEST_LAB_H_
#define UNIT_TEST_LAB_H_

#include "../MCAL/DIO_DRIVER/DIO.h"
#include "../MCAL/LED_DRIVER/LED.h"
#include "../MCAL/TIMER_DRIVER/TIMER.h"
#include "../MCAL/EXT_INTERRUPTS_DRIVER/EXT_INTERRUPTS.h"

void TestLEDS_Init();

void TestSUCCESS_LED();

void TestFAIL_LED();

void Testing_LED_DRIVER(uint8_t ledPin, uint8_t ledPort);

void Testing_TIMER_DRIVER(uint32_t prescaler, float timeDelay);

#endif /* UNIT_TEST_LAB_H_ */