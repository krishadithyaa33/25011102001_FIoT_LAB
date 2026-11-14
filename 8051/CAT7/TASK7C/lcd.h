/*
 * 16x2 Character LCD Driver Header for 8051
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#ifndef LCD_H
#define LCD_H

#include <reg51.h>

#define LCD_DATA_BUS P0

sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_EN = P2^2;

void lcd_delay(unsigned int ms);
void lcd_send_command(unsigned char cmd);
void lcd_send_data(unsigned char data_byte);
void lcd_init(void);
void lcd_write_string(const char *str);
void lcd_set_cursor(unsigned char row, unsigned char col);

#endif
