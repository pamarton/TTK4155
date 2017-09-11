/*
 * i_o.c
 *
 * Created: 11.09.2017 12:17:11
 *  Author: jonasgl
 */ 


#include "i_o.h"



int set_direction(unsigned int dir_reg, unsigned int pin, unsigned int mode){//sets the direction of the port (input or output) and returns 1 if successful
	if (mode == INPUT){
		dir_reg &= !(1 << pin);
	}else if (mode == OUTPUT){
		dir_reg |= (1 << pin);
	}else{
		return 0;
	}
	return 1;
}
uint8_t set_pin(uint8_t * port, uint8_t pin, uint8_t val){ //sets pins, returns value of 1 if successful
	*port |= (1 << pin);
	
	if (val == ON){
		//PORTA |= (1 << pin);
	}else if (val == OFF){
		//&port &= !(1 << pin);
	}else{
		return 0;
	}
	return 1;
}
/*int set_pinA(unsigned int pin, unsigned int val){
	return set_pin(PORTA, pin, val);
}
int set_pinB(unsigned int pin, unsigned  int val){
	return set_pin(PORTB, pin, val);
}
int set_pinC(unsigned int pin, unsigned int val){
	return set_pin(PORTC, pin, val);
}
int set_pinD(unsigned int pin, unsigned int val){
	return set_pin(PORTD, pin, val);
}*/