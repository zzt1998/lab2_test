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
    	DDRB = 0x00; PORTB = 0xFF;
    	DDRC = 0x00; PORTA = 0xFF;
    	DDRD = 0xFF; PORTB = 0x00;
    	unsigned char shf;
    	unsigned char ta = 0x00;
    	unsigned char tb = 0x00;
    	unsigned char tc = 0x00;
    	unsigned char D = 0x00;
	/* Insert your solution below */
	while (1) {
    	ta = PINA;
    	tb = PINB;
    	tc = PINC;
    	D = (ta + tb + tc) >140;
    	D = D + ((abs(ta - tc) > 80) << 1);
    	shf = ((ta + tb + tc)/3 >>2) <<2;
    	PORTD = shf + (D & 0x03);
	}
	return 1;
}

