/*
 * i_o.h
 *
 * Created: 11.09.2017 12:17:20
 *  Author: jonasgl
 */ 


#ifndef I_O_H_
#define I_O_H_

#define INPUT 0
#define OUTPUT 1
#define OFF 0
#define ON 1

#include <avr/io.h>
int set_direction(unsigned int dir_reg, unsigned int pin, unsigned int mode);//sets the direction of the port (input or output) and returns 1 if successful

uint8_t set_pin(uint8_t * port, uint8_t pin, uint8_t val);//sets pins, returns value of 1 if successful
/*
int set_pinA(unsigned int pin, unsigned int val);
int set_pinB(unsigned int pin, unsigned int val);
int set_pinC(unsigned int pin, unsigned int val);
int set_pinD(unsigned int pin, unsigned int val);
*/
#endif /* I_O_H_ */