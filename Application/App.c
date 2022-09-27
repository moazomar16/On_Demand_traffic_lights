/*
 * App.c
 *
 * Created: 9/27/2022 2:25:26 PM
 *  Author: moaz omar
 */ 

#include "App.h"


Traffic_State Cars={0,0};
// Select mode
uint8_t RUNNING_MODE =NormalMode; 
App_init(){
	
	// Cars led
	LED_init(0,PORT_A);
	LED_init(1,PORT_A);
	LED_init(2,PORT_A);
	
	// Pedestrian led
	LED_init(0,PORT_B);
	LED_init(1,PORT_B);
	LED_init(2,PORT_B);
	
	// initializing External Interrupt pin to be input
	Button_init(2,PORT_D);
	
	// initialize Timer in normal mode
	TimerNormal_init();
	
	// enable interrupts
	INT0_init(FALLING_EDGE);
	
	
}

App_Start(){
	LED_on(0,PORT_B); // turn pedestrian red led on
	while(1){
		switch (RUNNING_MODE)
		{
		case NormalMode:
			if (Cars.Next_State == RED )  // check if the next light is red
			{
				Cars.LED_State=RED; // stating the the current light is red
				Cars.Next_State=YELLOW; // informing that the next led is yellow
				LED_on(0,PORT_A); // turn red light on and wait for 5 second then turn it off 
				Timer_delay(5);
				LED_off(0,PORT_A);
				
				break;
			}
			else if (Cars.Next_State == YELLOW ) // check if the next light is yellow
			{
				if (Cars.LED_State == RED)    // check if the last light is red
				{
					Cars.Next_State = GREEN;       // informing that the next led is green
				}
				else if (Cars.LED_State == GREEN)     // check if the last light is green
				{
					Cars.Next_State = RED;     // informing that the next led is red
				}
				Cars.LED_State = YELLOW;     // blink yellow light on and off for 5 second 
				LED_blink(1,PORT_A,5);
				break;
			}
			else if (Cars.Next_State=GREEN)
			{
			   // the next light is green
				LED_on(2,PORT_A);   // turn green light on and wait for 5 second then turn it off 
				Timer_delay(5);
				LED_off(2,PORT_A);
				Cars.LED_State=GREEN;    // stating the the current light is green
				Cars.Next_State=YELLOW;   // informing that the next led is yellow
				break;
			}
				
			
		
		case PedestrianMode:
				if (Cars.LED_State == RED)
				{
					LED_off(0,PORT_B); // pedestrian red off 
					LED_on(0,PORT_A);  // cars red on
					LED_on(2,PORT_B);  // pedestrian green on
					Timer_delay(5);    // wait for 5 second 
				}
				else if (Cars.LED_State == YELLOW || Cars.LED_State == GREEN)
				{
					LED_on(0,PORT_B); // pedestrian red on
					LED_blink_2leds(1,PORT_A,1,PORT_B,5);
					LED_off(0,PORT_B); // pedestrian red off
					LED_on(0,PORT_A);  // cars red is on
					LED_on(2,PORT_B);  // pedestrian green on 
					Timer_delay(5);
					
				}
				LED_off(0,PORT_A);  // cars red off
				LED_off(2,PORT_B);  // pedestrian green off
				LED_blink_2leds(1,PORT_A,1,PORT_B,5); // blink both yellow lights on and off
				LED_on(2,PORT_A);   //cars green on
				LED_on(0,PORT_B);	// pedestrian red on 
				Timer_delay(5);
				LED_off(2,PORT_A);
				Cars.LED_State=GREEN;
				Cars.Next_State=YELLOW;
				RUNNING_MODE= NormalMode;
				Enable_Global_Interrupt();
				break;		
		}
	}
}

ISR(EXT_INT0)
{
	
	RUNNING_MODE= PedestrianMode;
	Disable_Global_Interrupt();
	
}