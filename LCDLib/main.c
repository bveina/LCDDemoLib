/*
 * LCDLib.c
 *
 * Created: 11/13/2019 1:22:50 PM
 * Author : u_bviall
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"


int main(void)
{
	DDRB |= 7;
	PORTB |=2;
	DDRD |= (1<<5);
	TCCR0A = (0b10 << COM0B0) | (0b11<<WGM00);
	TCCR0B = (3<<CS00);
	OCR0B =0x70;
	DDRC=0xf;
	
	
	LCD_init_4bit();
	
    /* Replace with your application code */
    while (1) 
    {
		putChar('G');
		_delay_ms(1000);
    }
}

