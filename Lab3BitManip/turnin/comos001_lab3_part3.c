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
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char level = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char i = 0x00;

	while (1) {

	i = 0x00;
	level = 0x00;
	tmpC = 0x00;
	PORTC = 0x00;
	
	for (i = 0x01; i <= 0x08; i = 2 * i)
	{
		if((PINA & i) == i)
		{
			level = level  + i;
		}
	}

	if (level == 0)
	{
		tmpC = tmpC | 64;	
	}
	else if (level <= 2)
	{
		tmpC = tmpC | 64;
		tmpC  = tmpC  | 32;	
	}
	else if (level <= 4)
	{
		tmpC = tmpC | 64;
		tmpC = tmpC | 32;
		tmpC = tmpC | 16;
	}
	else if (level <= 6)
	{
		tmpC = tmpC | 32;
		tmpC = tmpC | 16;
		tmpC = tmpC | 8;
	}
	else if (level <= 9)
	{
		tmpC = tmpC | 32;
		tmpC = tmpC | 16;
		tmpC = tmpC | 8;
		tmpC = tmpC | 4;
	}
	else if (level <= 12)
	{
		tmpC = tmpC | 32;
		tmpC = tmpC | 16;
		tmpC = tmpC | 8;
		tmpC = tmpC | 4;
		tmpC = tmpC | 2;	
	}
	else //13- 15
	{
		tmpC = tmpC | 32;
		tmpC = tmpC | 16;
		tmpC = tmpC | 8;
		tmpC = tmpC | 4;
		tmpC = tmpC | 2;
		tmpC = tmpC | 1;	
	}
	if ((PINA & 0x70) == 0x30)
	{
		tmpC = tmpC | 128; 
	}
	
	PORTC = tmpC;

    }
    return 1;
}
