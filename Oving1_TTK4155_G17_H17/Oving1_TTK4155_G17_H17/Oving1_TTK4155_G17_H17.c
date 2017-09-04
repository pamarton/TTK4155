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
#include <util/delay.h>
#include <avr/interrupt.h>
void send_UART(char letter);
void init_UART(unsigned int ubbr);
unsigned int recieve_UART(void);

int main(void)
{
	init_UART(UBBR);
	printf("testing");
	unsigned char temp = ' ';

	while(1){
		temp = recieve_UART();
		if (temp != 0){
			send_UART(temp);
		}
	};
}

void send_UART(char letter){
	//send UART melding
	while( !(UCSR0A & (1<<UDRE0)) );
	UDR0 = letter;
}

void init_UART(unsigned int ubrr){
	//set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)(ubrr);
	//enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	fdevopen((int(*)(char, struct __file*))&send_UART, (int(*)(struct __file*))&recieve_UART);
}

unsigned int recieve_UART(void){
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

