/*
 * BUTTON.h
 *
 * Created: 9/14/2022 8:10:15 PM
 *  Author: Moaz Omar
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

// including DIO driver 
#include "../../MCAL/DIO_Driver/DIO.h"



// APIs
void Button_init(uint8_t ButtonPin_Number, uint8_t ButtonPort_Number);
void Button_read(uint8_t ButtonPin_Number, uint8_t ButtonPort_Number, uint8_t *value);




#endif /* BUTTON_H_ */