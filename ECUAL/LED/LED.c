/*
 * LED.c
 *
 * Created: 9/14/2022 8:09:08 PM
 *  Author: moazo
 */ 


#include "LED.h"

void LED_init(uint8_t LedPin_Number, uint8_t LedPort_Number){
	DIO_init(LedPin_Number,LedPort_Number,OUT);
}
void LED_on(uint8_t LedPin_Number, uint8_t LedPort_Number){
	DIO_write(LedPin_Number,LedPort_Number,HIGH);
}
void LED_off(uint8_t LedPin_Number, uint8_t LedPort_Number){
	DIO_write(LedPin_Number,LedPort_Number,LOW);
}
void LED_toggle(uint8_t LedPin_Number, uint8_t LedPort_Number){
	DIO_toggle(LedPin_Number,LedPort_Number);
}
void LED_blink(uint8_t LedPin_Number, uint8_t LedPort_Number,uint8_t delay){
	int i;
	for (i=0; i<delay;i++)
	{
		DIO_write(LedPin_Number,LedPort_Number,HIGH);
		Timer_delay(0.5);
		DIO_toggle(LedPin_Number,LedPort_Number);
		Timer_delay(0.5);
	}
	
}
void LED_blink_2leds(uint8_t LedPin_Number1, uint8_t LedPort_Number1,uint8_t LedPin_Number2, uint8_t LedPort_Number2,uint8_t delay){
	int i;
	for (i=0; i<delay;i++)
	{
		DIO_write(LedPin_Number1,LedPort_Number1,HIGH);
		DIO_write(LedPin_Number2,LedPort_Number2,HIGH);
		Timer_delay(0.5);
		DIO_toggle(LedPin_Number1,LedPort_Number1);
		DIO_toggle(LedPin_Number2,LedPort_Number2);
		Timer_delay(0.5);
	}
	
}