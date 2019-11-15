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
#define RS_BIT 0
#define RS_PORT PORTB
#define RW_BIT 1
#define RW_PORT PORTB
#define E_BIT 2
#define E_PORT PORTB

#define DATA_PORT PORTC

#define DATA_BIT 0
#define DATA_MASK (0xf<< DATA_BIT)


#define RS_CMD 0
#define RS_DATA 1

#define LCD_FUNCTION_RESET 0x30
#define LCD_FUNCTION_SET_8BIT 0x38
#define LCD_FUNCTION_SET_4BIT 0x28
#define LCD_DISPLAY_OFF 0x08
#define LCD_CLEAR 0x01
#define LCD_ENTRY_MODE 0x06
#define LCD_DISPLAY_ON 0x0C
#define LCD_HOME 0x02
#define LCD_SET_CURSOR 0x80


// prototypes
void LCD_init_4bit();
void putChar(uint8_t x);
void setXY(uint8_t x, uint8_t y);
void writeByte(uint8_t b,uint8_t RS);


void WriteCommand(uint8_t b);

// low level
void xmit_byte(uint8_t b);
void xmit_nibble(uint8_t nib);


#endif /* LCD_H_ */