/*
 * On_Demand_traffic_lights.c
 *
 * Created: 9/14/2022 7:54:47 PM
 * Author : Moaz Omar
 */ 

//#include "MCAL/DIO_Driver/DIO.h"

#include "ECUAL/LED/LED.h"
#include "ECUAL/BUTTON/BUTTON.h"
#include "MCAL/Timer_Driver/Timer.h"


int main(void)
{
	uint8_t button_state;
	
/*    DIO_init(4,PORT_A,OUT);
	DIO_init(5,PORT_B,OUT);
	DIO_init(2,PORT_C,OUT);
	DIO_init(0,PORT_D,OUT);
	
	LED_init(2,PORT_C);*/
	LED_init(5,PORT_B);
	Button_init(5,PORT_A);
	TimerNormal_init();
	
    while (1) 
    {
		/*DIO_write(4,PORT_A,HIGH);
		DIO_write(5,PORT_B,LOW);
		DIO_write(2,PORT_C,HIGH);
		DIO_write(0,PORT_D,LOW);
		
		
		for (int i=0;i<2000;i++);
		LED_off(5,PORT_B);
		LED_off(2,PORT_C);
		for (int i=0;i<2000;i++);
		LED_on(2,PORT_C);
		
		*/
		LED_off(5,PORT_B);
		Button_read(5,PORT_A,&button_state);
		while (button_state == HIGH)
		{
			LED_on(5,PORT_B);
			Timer_delay1();
			LED_off(5,PORT_B);
			Timer_delay1();
			Button_read(5,PORT_A,&button_state);
		}

		
    }
}

