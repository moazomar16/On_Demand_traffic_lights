/*
 * interupt.h
 *
 * Created: 9/23/2022 11:59:32 AM
 *  Author: moazo
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../registers.h"
#include "../../types.h"

// define isr prototype
#define ISR(vector,...) \
void vector(void)__attribute__((signal,__INTR_ATTRS))__VA_ARGS__;   \
void vector(void)

// definition to function like macro that enable and disable global interrupt 
#define Disable_Global_Interrupt() __asm__ __volatile__("cli" ::: "memory")
#define Enable_Global_Interrupt()  __asm__ __volatile__("sei" ::: "memory")

// external interrupt requests
#define EXT_INT0 __vector_1     // external interrupt request 0
#define EXT_INT1 __vector_2     // external interrupt request 0
#define EXT_INT2 __vector_3     // external interrupt request 0

// Interrupts Sense Control
#define LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RAISING_EDGE 3

// status
typedef enum Interrupt_status{
	Interrupt_OK,
	Interrupt_Error
}Interrupt_status;

// APIs
Interrupt_status INT0_init(uint8_t Sense_Mode);
Interrupt_status INT1_init(uint8_t Sense_Mode);
Interrupt_status INT2_init(uint8_t Sense_Mode);

#endif /* INTERRUPT_H_ */