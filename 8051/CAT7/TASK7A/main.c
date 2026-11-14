/*
 * Experiment: CAT7 - Task 7A: Static String Rendering
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include "lcd.h"

void main(void) {
    lcd_init();
    
    lcd_set_cursor(0, 0);
    lcd_write_string("FIoT LAB - 8051");
    
    lcd_set_cursor(1, 0);
    lcd_write_string("Krish 25011102001");
    
    while (1);
}
