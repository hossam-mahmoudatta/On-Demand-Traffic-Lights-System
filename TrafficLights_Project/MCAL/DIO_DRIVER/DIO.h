/*
 * dio.h
 *
 * Created: 8/11/2022 2:09:54 PM
 *  Author: TESTER
 */ 

/******************************************************************/
/*            Creating Your Own Library: Register File            */
/*                   1. Create Register File                      */
/*                   2. Create Driver Library                     */
/*            Driver Library Consists of .c & .h Files            */
/******************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "DIO_REGISTERS.h"
#include "DIO_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

typedef enum EN_DIO_Error_t {
	DIO_OK,
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_DIRECTION
} EN_DIO_Error_t;


EN_DIO_Error_t DIO_Init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
// Initializes DIO Direction

EN_DIO_Error_t DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
// Write Data to DIO

EN_DIO_Error_t DIO_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);
// Read DIO

EN_DIO_Error_t DIO_Toggle(uint8_t pinNumber, uint8_t portNumber);
// Toggle DIO

#endif /* DIO_H_ */