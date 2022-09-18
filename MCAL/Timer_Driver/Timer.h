/*
 * Timer.h
 *
 * Created: 9/14/2022 8:07:16 PM
 *  Author: moazo
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../registers.h"

#define PRESCALER 1024

// APIs
void TimerNormal_init();
void Timer_delay(float delay);
void Timer_start(uint8_t prescaler);
void Timer_off();



#endif /* TIMER_H_ */