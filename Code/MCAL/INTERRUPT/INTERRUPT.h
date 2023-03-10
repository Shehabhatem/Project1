#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/Macros.h"
#include "../../Utilities/Register.h"

#define EXT_INT_0	__vector_1
#define EXT_INT_1	__vector_2
#define EXT_INT_2	__vector_3
#define TIMER_0_OVF __vector_11

#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

void INTERRUPT_global_init();
void INTERRUPT_0_init();
void INTERRUPT_T0_ovf_init();




#endif