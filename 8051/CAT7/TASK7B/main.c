/*
 * Experiment: CAT7 - Task 7B: Display Shift & Custom Character
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include "lcd.h"

code unsigned char custom_heart[8] = {
    0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00
};

void load_custom_char(unsigned char loc, unsigned char *pattern) {
    unsigned char i;
    lcd_send_command(0x40 + (loc * 8));
    for (i = 0; i < 8; i++) {
        lcd_send_data(pattern[i]);
    }
}

void main(void) {
    lcd_init();
    load_custom_char(0, custom_heart);
    
    lcd_set_cursor(0, 2);
    lcd_write_string("IoT System ");
    lcd_send_data(0);
    
    lcd_set_cursor(1, 0);
    lcd_write_string("Custom Graphics");
    
    while (1) {
        lcd_delay(800);
        lcd_send_command(0x18);
    }
}
