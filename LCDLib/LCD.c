/*
 * LCD.c
 *
 * Created: 11/13/2019 1:23:50 PM
 *  Author: u_bviall
 */ 
#include "LCD.h"

void LCD_init()
{
//33, 32, and 28 in hex. 
	writeByte(0x33,RS_CMD);	
	writeByte(0x32,RS_CMD);	
	writeByte(0x28,RS_CMD);	
}

void putChar(uint8_t x)
{
	writeByte(x,1);
}



void setXY(uint8_t x, uint8_t y)
{
	// address start at 0x80,0xc0
	// byte 0x80+y*0x40+x
	uint8_t val = 0x80+y*0x40+x;
	writeByte(val,0);
}

// low level library function

void writeByte(uint8_t b,uint8_t RS)
{
	if (RS)
		RS_PORT |= 1<<RS_BIT;
	else
		RS_PORT &= ~(1<<RS_BIT);	
	RW_PORT &= ~(1<<RW_BIT);
	xmit_byte(b);
	//xmit_nibble(b>>4);
	//xmit_nibble(b&0xf);
}

void E_hi2lo()
{
	E_PORT |= 1<<E_BIT;
	_delay_us(1);
	E_PORT &= ~(1<<E_BIT);
	_delay_us(1);
}

void xmit_byte(uint8_t b)
{
	//PORTD = b; //example of 8 bit mode
	//E_hi2lo()
	
	xmit_nibble((b>>4));
	xmit_nibble((b&0xf));
}

void xmit_nibble(uint8_t nib)
{
	DATA_PORT = (nib) << DATA_BIT;
	//pulse the E bit (hi to lo transition)
	E_hi2lo();
}
