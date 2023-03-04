#include "TIMER.h"

extern uint8_t count;
extern uint8_t first_click;

uint8_t ovf;

void static (*callbackvar)(uint8_t portname, uint8_t pinnum);

void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum)){
	callbackvar = cbvar;
}


void TIMER_0_init(){
	
	TCCR0 |= ((0<<3) | (0<<6));
	
	TIMER_0_set_init_value(init_value);
}

void TIMER_0_set_init_value(uint8_t val){
	
	TCNT0 = val;
}
	
void TIMER_0_start(){
	
	TCCR0 |= ((1<<0) | (1<<2));
	
	while(ovf <20);
}


void TIMER_0_stop(){
	
	TCCR0 = 0;
	
	ovf = 0;
}


void TIMER_0_delay(){
	TIMER_0_start();
	TIMER_0_stop();
}

void TIMER_reset(){
	TIMER_0_set_init_value(init_value);
	ovf = 0;
}


ISR(TIMER_0_OVF){

	TIMER_0_set_init_value(init_value);
	

	ovf++;
	

	if(count== phase_2 || count == phase_4){
		
		if(!first_click){
			callbackvar(CAR_light, LED_yellow);
		}
		
		else if(first_click){
				callbackvar(CAR_light, LED_yellow);
				callbackvar(PED_light, LED_yellow);
		}
	}
}