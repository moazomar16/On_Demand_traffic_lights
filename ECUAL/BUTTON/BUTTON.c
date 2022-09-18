/*
 * BUTTON.c
 *
 * Created: 9/14/2022 8:10:01 PM
 *  Author: moazo
 */ 

#include "BUTTON.h"

// this function is going to initialize the pins to be used with buttons
void Button_init(uint8_t ButtonPin_Number, uint8_t ButtonPort_Number){
	DIO_init(ButtonPin_Number, ButtonPort_Number, IN);
}

// this function is going to check is the button is pressed or not
void Button_read(uint8_t ButtonPin_Number, uint8_t ButtonPort_Number, uint8_t *value){
	DIO_read(ButtonPin_Number,ButtonPort_Number,value);
}