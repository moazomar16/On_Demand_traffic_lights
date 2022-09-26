/*
 * DIO.c
 *
 * Created: 9/14/2022 8:05:43 PM
 *  Author: Moaz Omar 
 */ 


#include "DIO.h"

// this function is going to initialize the given pin 
DIO_status DIO_init  (uint8_t pin_number,uint8_t Port_number,uint8_t pin_direction){
	switch (Port_number)
	{
		case PORT_A:
			if(pin_direction == IN){
				DDRA &= ~(1<<pin_number); // Setting the pin direction to be INPUT
				return DIO_OK;
				}
			else if (pin_direction == OUT){
				DDRA |= (1<<pin_number);  // Setting the pin direction to be OUTPUT
				return DIO_OK;
			}
			else
				return DIO_cant_init;
			break;
			
		case PORT_B:
			if(pin_direction == IN){
				DDRB &= ~(1<<pin_number); // INPUT
				return DIO_OK;
			}
			else if (pin_direction == OUT){
				DDRB |= (1<<pin_number);  // OUTPUT
				return DIO_OK;
			}
			else
				return DIO_cant_init;
			break;
		
		case PORT_C:
			if(pin_direction == IN){
				DDRC &= ~(1<<pin_number); // INPUT
				return DIO_OK;
				}
			else if (pin_direction == OUT){
				DDRC |= (1<<pin_number);  // OUTPUT
				return DIO_OK;
			}
			else
				return DIO_cant_init;
			break;
		
		case PORT_D:
			if(pin_direction == IN){
				DDRD &= ~(1<<pin_number); // INPUT
				return DIO_OK;
				}
			else if (pin_direction == OUT){
				DDRD |= (1<<pin_number);  // OUTPUT
				return DIO_OK;
			}
			else
				return DIO_cant_init;
			break;
		
		
	}
}

// this function is going to write on pins
DIO_status DIO_write (uint8_t pin_number,uint8_t Port_number,uint8_t value)
{
	switch (Port_number)
	{
		case PORT_A:
		if(value == LOW){
			PORTA &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
			}
		else if (value == HIGH){
			PORTA |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
			}
		else {
			return DIO_cant_write;
			}
		break;
		
		case PORT_B:
		if(value == LOW){
			PORTB &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
			}
		else if (value == HIGH){
			PORTB |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
			}
		else {
			return DIO_cant_write;
			}
		break;
		
		case PORT_C:
		if(value == LOW){
			PORTC &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
			}
		else if (value == HIGH){
			PORTC |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
			}
		else {
			return DIO_cant_write;
			}
		break;
		
		case PORT_D:
		if(value == LOW){
			PORTD &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
			}
		else if (value == HIGH){
			PORTD |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
			}
		else {
			return DIO_cant_write;
			}
		break;
	}
} 

//this function is going to read the pins
DIO_status DIO_read  (uint8_t pin_number,uint8_t Port_number,uint8_t *value){
	switch (Port_number)
	{
		case PORT_A:
		if(((PINA&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			return DIO_OK;
			}
		else if (((PINA&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			return DIO_OK;
			}
		else {
			return DIO_cant_read;
			}
		break;
		
		case PORT_B:
		if(((PINB&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			return DIO_OK;
			}
		else if (((PINB&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			return DIO_OK;
			}
		else {
			return DIO_cant_read;
			}
		break;
		
		case PORT_C:
		if(((PINC&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			return DIO_OK;
			}
		else if (((PINC&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			return DIO_OK;
			}
		else {
			return DIO_cant_read;
			}
		break;
		
		case PORT_D:
		if(((PIND&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			return DIO_OK;
			}
		else if (((PIND&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			return DIO_OK;
			}
		else {
			return DIO_cant_read;
			}
		break;
	}
}

// this function is going to toggle the pins
DIO_status DIO_toggle(uint8_t pin_number,uint8_t Port_number){
	switch (Port_number)
	{
		case PORT_A:
		if(((PINA&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTA |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
		}
		else if (((PINA&(1<<pin_number))>>pin_number) == HIGH){
			PORTA &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
		}
		else {
			return DIO_cant_toggle;
		}
		break;
		
		case PORT_B:
		if(((PINB&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTB |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
		}
		else if (((PINB&(1<<pin_number))>>pin_number) == HIGH){
			PORTB &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;		
		}
		else {
			return DIO_cant_toggle;
		}
		break;
		
		case PORT_C:
		if(((PINC&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTC |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
		}
		else if (((PINC&(1<<pin_number))>>pin_number) == HIGH){
			PORTC &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
		}
		else {
			return DIO_cant_toggle;
		}
		break;
		
		case PORT_D:
		if(((PIND&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTD |= (1<<pin_number);  // Set the pin State to be HIGH
			return DIO_OK;
		}
		else if (((PIND&(1<<pin_number))>>pin_number) == HIGH){
			PORTD &= ~(1<<pin_number); // Set the pin State to be LOW
			return DIO_OK;
		}
		else {
			return DIO_cant_toggle;
		}
		break;
	}
}
