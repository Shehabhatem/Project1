#ifndef MACROS_H_
#define MACROS_H_

	typedef unsigned char uint8_t;
	
	
	#define set_pin(x,n) x|= (1<<n)
	#define clr_pin(x,n) x&= ~(1<<n)
	#define tgl_pin(x,n) x^= (1<<n)
	#define get_pin(x,n) ((x&(1<<n))>>n)
	

	#define PORT_A 'A'
	#define PORT_B 'B'
	#define PORT_C 'C'
	#define PORT_D 'D'


	#define CAR_light PORT_A
	#define PED_light PORT_B


	#define LED_green	0
	#define LED_yellow	1
	#define LED_red		2

	
	#define BUTTON_port PORT_D

	#define BUTTON_pin	0
	
	#define phase_1 0
	#define phase_2 1
	#define phase_3 2
	#define phase_4 3
	
	
#endif 