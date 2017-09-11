/*
 * Oving1_TTK4155_G17_H17.c
 *
 * Created: 04.09.2017 11:50:29
 *  Author: pamarton
 */ 
#include <stdio.h>
#define F_CPU 4915200 // clock frequency in Hz
#define BAUDRATE 9600 // Valgt verdi data sendt pr sekund
#define UBBR 32 - 1 //F_CPU/(16*BAUDRATE)-1 //USART BAUD RATE REGISTER VALUE
#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
#include "uart.h"
#include "i_o.h"
int main(void)
{
	init_UART(UBBR);
	
	DDRA = 0xFF;
	
	set_pin(&PORTA, PINA4, ON);
	
	testUart();
	while (1)
	{
		printf("placeholder\n");
	}
}