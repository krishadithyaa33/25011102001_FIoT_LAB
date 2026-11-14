/*
 * 16x2 Character LCD Driver Implementation
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include "lcd.h"

void lcd_delay(unsigned int ms) {
    unsigned int u, v;
    for (u = 0; u < ms; u++) {
        for (v = 0; v < 120; v++);
    }
}

void lcd_send_command(unsigned char cmd) {
    LCD_DATA_BUS = cmd;
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 1;
    lcd_delay(2);
    LCD_EN = 0;
    lcd_delay(2);
}

void lcd_send_data(unsigned char data_byte) {
    LCD_DATA_BUS = data_byte;
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_EN = 1;
    lcd_delay(2);
    LCD_EN = 0;
    lcd_delay(2);
}

void lcd_init(void) {
    lcd_delay(20);
    lcd_send_command(0x38);
    lcd_send_command(0x0C);
    lcd_send_command(0x06);
    lcd_send_command(0x01);
    lcd_delay(5);
}

void lcd_write_string(const char *str) {
    while (*str) {
        lcd_send_data(*str++);
    }
}

void lcd_set_cursor(unsigned char row, unsigned char col) {
    unsigned char address = (row == 0) ? (0x80 + col) : (0xC0 + col);
    lcd_send_command(address);
}
