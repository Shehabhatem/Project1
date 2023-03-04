#include "BUTTON.h"

extern uint8_t ovf;
extern uint8_t count;
extern uint8_t first_click;


void BUTTON_init(uint8_t portname, uint8_t pinnum){
	DIO_init(portname, pinnum, IN);
}


void BUTTON_read(uint8_t portname, uint8_t pinnum, uint8_t* result){
	DIO_read(portname, pinnum, result);
}

ISR(EXT_INT_0){
	
	

	
	if(!first_click){
		
		
		if(count == phase_1){
			ovf=20;
		}
		
		
		else if(count == phase_2){
			
			
			LED_off(CAR_light, LED_yellow);
			LED_off(PED_light, LED_yellow);
			
			TIMER_reset();
		}
		
		
		else if(count == phase_3){
			TIMER_reset();
			LED_off(PED_light, LED_red);
			LED_on(PED_light, LED_green);
		}
		

		else if(count == phase_4){
			ovf=20;
			count = phase_2;
		}
		

		first_click=1;
	}
}