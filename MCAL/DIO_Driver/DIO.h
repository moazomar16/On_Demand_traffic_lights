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



// APIs
void DIO_init  (uint8_t pin_number,uint8_t Port_number,uint8_t pin_direction); //initializing pins
void DIO_write (uint8_t pin_number,uint8_t Port_number,uint8_t value); //writing on pins
void DIO_read  (uint8_t pin_number,uint8_t Port_number,uint8_t *value); //reading from pins
void DIO_toggle(uint8_t pin_number,uint8_t Port_number); //toggling pin

#endif /* DIO_H_ */