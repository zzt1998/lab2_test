/*	Author: zzhan171
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
	/* Insert DDR and PORT initializations */
    	DDRA = 0x00; PORTA = 0xFF;
    	DDRB = 0xFF; PORTB = 0x00;
    	DDRA = 0x00; PORTA = 0xFF;
    	DDRB = 0xFF; PORTB = 0x00;
    	unsigned char cnt = 0x00;
    	unsigned char tmpA = 0x00;
    	unsigned char pc = 0x00;
	/* Insert your solution below */
	while (1) {
    	tmpA = PINA;
    	cnt = ((tmpA & 0x01)==0x01) + ((tmpA & 0x02)==0x02) + ((tmpA & 0x04)==0x04) + ((tmpA & 0x08)==0x08);
    	pc = ((tmpA & 0x01)==0x01) && ((tmpA & 0x02)==0x02) && ((tmpA & 0x04)==0x04) && ((tmpA & 0x08)==0x08);
    	PORTB = cnt + (pc<<7);
	}
	return 1;
}

