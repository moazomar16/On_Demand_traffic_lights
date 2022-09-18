/*
 * LED.h
 *
 * Created: 9/14/2022 8:09:22 PM
 *  Author: moazo
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/DIO.h"

// APIs
void LED_init(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_on(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_off(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_toggle(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_blink(uint8_t LedPin_Number, uint8_t LedPort_Number);




#endif /* LED_H_ */