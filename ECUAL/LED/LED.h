/*
 * LED.h
 *
 * Created: 9/14/2022 8:09:22 PM
 *  Author: moazo
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/DIO.h"
#include "../../MCAL/Timer_Driver/Timer.h"

// APIs
void LED_init(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_on(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_off(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_toggle(uint8_t LedPin_Number, uint8_t LedPort_Number);
void LED_blink(uint8_t LedPin_Number, uint8_t LedPort_Number,uint8_t delay);
void LED_blink_2leds(uint8_t LedPin_Number1, uint8_t LedPort_Number1,uint8_t LedPin_Number2, uint8_t LedPort_Number2,uint8_t delay);




#endif /* LED_H_ */