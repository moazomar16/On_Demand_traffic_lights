/*
 * App.h
 *
 * Created: 9/23/2022 9:05:20 AM
 *  Author: moazo
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED/LED.h"
#include "../ECUAL/BUTTON/BUTTON.h"
#include "../MCAL/Timer_Driver/Timer.h"
#include "../MCAL/Interrupt_Driver/interrupt.h"


// Running Modes
#define NormalMode 0
#define PedestrianMode 1

// LED state
#define RED 0
#define YELLOW 1
#define GREEN 2


// structure for traffic state
typedef struct Traffic_State  
{
	uint8_t LED_State;
	uint8_t Next_State;
}Traffic_State;



// APIs
void App_init();
void App_Start();



#endif /* APP_H_ */