/*	Author: comos001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0X00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;

	while (1) {

	tmpA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	
	tmpA = (PINA & 0x0F);
	tmpA = tmpA << 4;
	PORTC = PORTC | tmpA;

	tmpA = (PINA & 0xF0);
	tmpA = tmpA >> 4;
	PORTB = PORTB | tmpA;
   }
return 1;	
}
