/*
 * DIO.c
 *
 * Created: 9/14/2022 8:05:43 PM
 *  Author: Moaz Omar 
 */ 


#include "DIO.h"

// this function is going to initialize the given pin 
void DIO_init  (uint8_t pin_number,uint8_t Port_number,uint8_t pin_direction){
	switch (Port_number)
	{
		case PORT_A:
			if(pin_direction == IN)
				DDRA &= ~(1<<pin_number); // Setting the pin direction to be INPUT
			else if (pin_direction == OUT)
				DDRA |= (1<<pin_number);  // Setting the pin direction to be OUTPUT
			else
				printf("Error cant initialize  ");
			break;
			
		case PORT_B:
			if(pin_direction == IN)
				DDRB &= ~(1<<pin_number); // INPUT
			else if (pin_direction == OUT)
				DDRB |= (1<<pin_number);  // OUTPUT
			else
				printf("Error cant initialize  ");
			break;
		
		case PORT_C:
			if(pin_direction == IN)
				DDRC &= ~(1<<pin_number); // INPUT
			else if (pin_direction == OUT)
				DDRC |= (1<<pin_number);  // OUTPUT
			else
				printf("Error cant initialize  ");
			break;
		
		case PORT_D:
			if(pin_direction == IN)
				DDRD &= ~(1<<pin_number); // INPUT
			else if (pin_direction == OUT)
				DDRD |= (1<<pin_number);  // OUTPUT
			else
				printf("Error cant initialize  ");
			break;
		
		
	}
}

// this function is going to write on pins
void DIO_write (uint8_t pin_number,uint8_t Port_number,uint8_t value)
{
	switch (Port_number)
	{
		case PORT_A:
		if(value == LOW){
			PORTA &= ~(1<<pin_number); // Set the pin State to be LOW
			}
		else if (value == HIGH){
			PORTA |= (1<<pin_number);  // Set the pin State to be HIGH
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
		
		case PORT_B:
		if(value == LOW){
			PORTB &= ~(1<<pin_number); // Set the pin State to be LOW
			}
		else if (value == HIGH){
			PORTB |= (1<<pin_number);  // Set the pin State to be HIGH
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
		
		case PORT_C:
		if(value == LOW){
			PORTC &= ~(1<<pin_number); // Set the pin State to be LOW
			}
		else if (value == HIGH){
			PORTC |= (1<<pin_number);  // Set the pin State to be HIGH
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
		
		case PORT_D:
		if(value == LOW){
			PORTD &= ~(1<<pin_number); // Set the pin State to be LOW
			}
		else if (value == HIGH){
			PORTD |= (1<<pin_number);  // Set the pin State to be HIGH
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
	}
} 

//this function is going to read the pins
void DIO_read  (uint8_t pin_number,uint8_t Port_number,uint8_t *value){
	switch (Port_number)
	{
		case PORT_A:
		if(((PINA&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			}
		else if (((PINA&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
		
		case PORT_B:
		if(((PINB&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			}
		else if (((PINB&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
		
		case PORT_C:
		if(((PINC&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			}
		else if (((PINC&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
		
		case PORT_D:
		if(((PIND&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			*value=LOW;
			}
		else if (((PIND&(1<<pin_number))>>pin_number) == HIGH){
			*value=HIGH;
			}
		else {
			printf("Error cant set the pin state ");
			}
		break;
	}
}

// this function is going to toggle the pins
void DIO_toggle(uint8_t pin_number,uint8_t Port_number){
	switch (Port_number)
	{
		case PORT_A:
		if(((PINA&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTA |= (1<<pin_number);  // Set the pin State to be HIGH
		}
		else if (((PINA&(1<<pin_number))>>pin_number) == HIGH){
			PORTA &= ~(1<<pin_number); // Set the pin State to be LOW
		}
		else {
			printf("Error cant toggle the pin  ");
		}
		break;
		
		case PORT_B:
		if(((PINB&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTB |= (1<<pin_number);  // Set the pin State to be HIGH
		}
		else if (((PINB&(1<<pin_number))>>pin_number) == HIGH){
			PORTB &= ~(1<<pin_number); // Set the pin State to be LOW
		}
		else {
			printf("Error cant toggle the pin ");
		}
		break;
		
		case PORT_C:
		if(((PINC&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTC |= (1<<pin_number);  // Set the pin State to be HIGH
		}
		else if (((PINC&(1<<pin_number))>>pin_number) == HIGH){
			PORTC &= ~(1<<pin_number); // Set the pin State to be LOW
		}
		else {
			printf("Error cant toggle the pin ");
		}
		break;
		
		case PORT_D:
		if(((PIND&(1<<pin_number))>>pin_number) == LOW){ // check if the pin state is LOW OR HIGH
			PORTD |= (1<<pin_number);  // Set the pin State to be HIGH
		}
		else if (((PIND&(1<<pin_number))>>pin_number) == HIGH){
			PORTD &= ~(1<<pin_number); // Set the pin State to be LOW
		}
		else {
			printf("Error cant toggle the pin ");
		}
		break;
	}
}
