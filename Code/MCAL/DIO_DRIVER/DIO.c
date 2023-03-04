
#include "DIO.h"


void DIO_init(uint8_t portname, uint8_t pinnum, uint8_t direction){
	
	switch(portname){
		case PORT_A:
			if(direction==OUT){
				set_pin(DDRA, pinnum);
			}else if(direction==IN){
				clr_pin(DDRA, pinnum);
			}
			break;
			
		case PORT_B:
			if(direction==OUT){
				set_pin(DDRB, pinnum);
			}else if(direction==IN){
				clr_pin(DDRB, pinnum);
			}
			break;
		
		case PORT_C:
			if(direction==OUT){
				set_pin(DDRC, pinnum);
			}else if(direction==IN){
				clr_pin(DDRC, pinnum);
			}
			break;
		
		case PORT_D:
			if(direction==OUT){
				set_pin(DDRD, pinnum);
			}else if(direction==IN){
				clr_pin(DDRD, pinnum);
			}
			break;		
	}
	
}


void DIO_write(uint8_t portname, uint8_t pinnum, uint8_t state){
	switch(portname){
		case PORT_A:
			if(state==HIGH){
				set_pin(PORTA, pinnum);
			}else if(state==LOW){
				clr_pin(PORTA, pinnum);
			}
			break;
		
		case PORT_B:
			if(state==HIGH){
				set_pin(PORTB, pinnum);
				}else if(state==LOW){
				clr_pin(PORTB, pinnum);
			}
			break;
		
		case PORT_C:
			if(state==HIGH){
				set_pin(PORTC, pinnum);
			}else if(state==LOW){
				clr_pin(PORTC, pinnum);
			}
			break;
		
		case PORT_D:
			if(state==HIGH){
				set_pin(PORTD, pinnum);
			}else if(state==LOW){
				clr_pin(PORTD, pinnum);
			}
			break;
	}
}


void DIO_toggle(uint8_t portname, uint8_t pinnum){
	switch(portname){
		case PORT_A:
			tgl_pin(PORTA, pinnum);
			break;
		
		case PORT_B:
			tgl_pin(PORTB, pinnum);
			break;
			
		case PORT_C:
			tgl_pin(PORTC, pinnum);
			break;
		
		case PORT_D:
			tgl_pin(PORTD, pinnum);
			break;
	}
}


void DIO_read(uint8_t portname, uint8_t pinnum, uint8_t* result){
		switch(portname){
			case PORT_A:
				*result = get_pin(PINA, pinnum);
				break;
			
			case PORT_B:
				*result = get_pin(PINB, pinnum);
				break;
			
			case PORT_C:
				*result = get_pin(PINC, pinnum);
				break;
			
			case PORT_D:
				*result = get_pin(PIND, pinnum);
				break;
		}
}


