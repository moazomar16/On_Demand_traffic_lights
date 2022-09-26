/*
 * DIO.h
 *
 * Created: 9/14/2022 8:06:36 PM
 *  Author: moazo
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../registers.h"
#include "stdio.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Pin Values
#define LOW 0
#define HIGH 1

// Pin directions
#define IN  0
#define OUT 1

typedef enum DIO_status{
	DIO_OK,
	DIO_cant_init,
	DIO_cant_write,
	DIO_cant_read,
	DIO_cant_toggle
}DIO_status;

// APIs
DIO_status DIO_init  (uint8_t pin_number,uint8_t Port_number,uint8_t pin_direction); //initializing pins  
DIO_status DIO_write (uint8_t pin_number,uint8_t Port_number,uint8_t value); //writing on pins
DIO_status DIO_read  (uint8_t pin_number,uint8_t Port_number,uint8_t *value); //reading from pins
DIO_status DIO_toggle(uint8_t pin_number,uint8_t Port_number); //toggling pin

#endif /* DIO_H_ */