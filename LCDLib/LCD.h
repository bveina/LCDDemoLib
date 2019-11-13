/*
 * LCD.h
 *
 * Created: 11/13/2019 1:23:42 PM
 *  Author: u_bviall
 */ 


#ifndef LCD_H_
#define LCD_H_

// includes
#include <avr/io.h>
#include <util/delay.h>
// defines
#define RS_BIT 2
#define RS_PORT PORTB
#define RW_BIT 3
#define RW_PORT PORTB
#define E_BIT 4
#define E_PORT PORTB

#define DATA_PORT PORTD

#define DATA_BIT 2
#define DATA_MASK (0xf<< DATA_BIT)


#define RS_CMD 0
#define RS_DATA 1

// prototypes
void LCD_init_4bit();
void putChar(uint8_t x);
void setXY(uint8_t x, uint8_t y);
void writeByte(uint8_t b,uint8_t RS);


// low level
void xmit_byte(uint8_t b);
void xmit_nibble(uint8_t nib);


#endif /* LCD_H_ */