/*
 * Timer.c
 *
 * Created: 9/14/2022 8:07:34 PM
 *  Author: moaz omar
 */ 


#include "Timer.h"
#include "math.h"


void TimerNormal_init(){
	TCCR0 = 0x00; // normal mode
	TCNT0 = 0x00; // initial value 
}
void Timer_delay(float delay){
	double Ttick,Tmaxdelay,Noverflows;
	uint8_t Tinit;
	uint16_t overflowcounter=0;
	Ttick = PRESCALER/1000000.0;
	Tmaxdelay = 256 * Ttick;
	Noverflows = ceil(delay/Tmaxdelay);
	Tinit = ceil(256 - ((delay/Ttick)/Noverflows));
	
	TCNT0 = Tinit;
	switch(PRESCALER){
		case 1:
			TCCR0 |= ((uint8_t)(1<<0));
			break;
		case 8:
			TCCR0 |= ((uint8_t)(1<<1));
			break;
		case 64:
			TCCR0 |= ((uint8_t)(0x03));
			break;	
		case 256:
			TCCR0 |= ((uint8_t)(0x04));
			break;
		case 1024:
			TCCR0 |= ((uint8_t)(0x05));
			break;
	}
	while(overflowcounter < Noverflows){
		while ((TIFR &(1<<0)) == 0);
		TIFR |=1<<0;
		overflowcounter++;
	}
	TCNT0=0x00;
}
void Timer_start(uint8_t prescaler){
	TCCR0 |= 1<<prescaler;
	while ((TIFR &(1<<0)) == 0);
	TIFR |=1<<0;
	TCNT0 = 0x00;
}
void Timer_off(){
	TCNT0 = 0x00;
}
