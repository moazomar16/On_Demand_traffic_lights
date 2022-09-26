/*
 * Interupt.c
 *
 * Created: 9/23/2022 11:58:56 AM
 *  Author: moazo
 */ 

#include "interrupt.h"


Interrupt_status INT0_init(uint8_t Sense_Mode){
	// enable global interrupt
	Enable_Global_Interrupt();
	switch(Sense_Mode){     // selecting interrupt sense control
		case LOW_LEVEL:
			MCUCR &= ~(1<<0); 
			MCUCR &= ~(1<<1); 
			break;
		case ANY_LOGICAL_CHANGE:
			MCUCR |= (1<<0); 
			break;
		case FALLING_EDGE:
			MCUCR |= (1<<1);
			break;
		case RAISING_EDGE:
			MCUCR |= (1<<0);
			MCUCR |= (1<<1);
			break;
		default:
			return Interrupt_Error;
			break;
		
	}
	
	GICR |= (1<<6);  // enable external interrupt 0
	return Interrupt_OK;
}
Interrupt_status INT1_init(uint8_t Sense_Mode){
	// enable global interrupt
	Enable_Global_Interrupt();
	switch(Sense_Mode){     // selecting interrupt sense control
		case LOW_LEVEL:
		MCUCR &= ~(1<<2);
		MCUCR &= ~(1<<3);
		break;
		case ANY_LOGICAL_CHANGE:
		MCUCR |= (1<<2);
		break;
		case FALLING_EDGE:
		MCUCR |= (1<<3);
		break;
		case RAISING_EDGE:
		MCUCR |= (1<<2);
		MCUCR |= (1<<3);
		break;
		default:
		return Interrupt_Error;
		break;
		
	}
	
	GICR |= (1<<7);  // enable external interrupt 1
	return Interrupt_OK;
}
Interrupt_status INT2_init(uint8_t Sense_Mode){
	// enable global interrupt
	Enable_Global_Interrupt();
	switch(Sense_Mode){     // selecting interrupt sense control
		case FALLING_EDGE:
		MCUCSR &= ~(1<<6);
		break;
		case RAISING_EDGE:
		MCUCSR |= (1<<6);
		break;
		default:
		return Interrupt_Error;
		break;
		
	}
	
	GICR |= (1<<5);  // enable external interrupt 1
	return Interrupt_OK;
}