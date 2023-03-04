
#include "INTERRUPT.h"

void INTERRUPT_global_init(){
	
	set_pin(SREG, 7);
}

void INTERRUPT_0_init(){

	set_pin(MCUCR, 0);
	set_pin(MCUCR, 1);
	set_pin(GICR, 6);
}


void INTERRUPT_T0_ovf_init(){
	
	set_pin(TIMSK, 0);
}

