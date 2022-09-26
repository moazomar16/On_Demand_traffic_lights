/*
 * registers.h
 *
 * Created: 9/16/2022 2:35:02 PM
 *  Author: moazo
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"


/************************************************************************/
/* DIO Registers                                                        */
/************************************************************************/

//PORTA Registers
#define PORTA *((vuint8_t *) 0x3B)
#define DDRA  *((vuint8_t *) 0x3A)
#define PINA  *((vuint8_t *) 0x39)

//PORTB Registers
#define PORTB *((vuint8_t *) 0x38)
#define DDRB  *((vuint8_t *) 0x37)
#define PINB  *((vuint8_t *) 0x36)

//PORTC Registers
#define PORTC *((vuint8_t *) 0x35)
#define DDRC  *((vuint8_t *) 0x34)
#define PINC  *((vuint8_t *) 0x33)

//PORTD Registers
#define PORTD *((vuint8_t *) 0x32)
#define DDRD  *((vuint8_t *) 0x31)
#define PIND  *((vuint8_t *) 0x30)


/************************************************************************/
/* Timers Registers                                                     */
/************************************************************************/

// Timer0 Registers
#define TCCR0 *((vuint8_t *) 0x53)
#define TCNT0 *((vuint8_t *) 0x52)
#define TIFR  *((vuint8_t *) 0x58)

// Timer1 Registers
#define TCCR1A *((vuint8_t *) 0x4F)
#define TCCR1B *((vuint8_t *) 0x4E)
#define TCNT1H *((vuint8_t *) 0x4D)
#define TCNT1L *((vuint8_t *) 0x4C)
#define OCR1AH *((vuint8_t *) 0x4B)
#define OCR1AL *((vuint8_t *) 0x4A)
#define OCR1BH *((vuint8_t *) 0x49)
#define OCR1BL *((vuint8_t *) 0x48)
#define ICR1H  *((vuint8_t *) 0x47)
#define ICR1L  *((vuint8_t *) 0x46)


// Timer2 Registers
#define TCCR2 *((vuint8_t *) 0x45)
#define TCNT2 *((vuint8_t *) 0x44)
#define OCR2  *((vuint8_t *) 0x43)


/************************************************************************/
/*Interrupt Registers                                                   */
/************************************************************************/


#define GICR    *((vuint8_t *) 0x5B)  // General interrupt control register 
#define GIFR    *((vuint8_t *) 0x5A)  // General interrupt flag register 
#define MCUCR   *((vuint8_t *) 0x55)  // MCU control register 
#define MCUCSR  *((vuint8_t *) 0x54)  // MCU control and status register 




#endif /* REGISTERS_H_ */