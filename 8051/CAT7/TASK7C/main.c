/*
 * Experiment: CAT7 - Task 7C: Dynamic Sensor Data Formatting
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include "lcd.h"

void display_integer(unsigned int val) {
    char buf[5];
    buf[0] = (val / 1000) % 10 + '0';
    buf[1] = (val / 100) % 10 + '0';
    buf[2] = (val / 10) % 10 + '0';
    buf[3] = (val % 10) + '0';
    buf[4] = '\0';
    lcd_write_string(buf);
}

void main(void) {
    unsigned int simulated_temp = 24;
    unsigned int simulated_lux = 450;
    
    lcd_init();
    
    while (1) {
        lcd_set_cursor(0, 0);
        lcd_write_string("Temp : ");
        display_integer(simulated_temp);
        lcd_write_string(" C");
        
        lcd_set_cursor(1, 0);
        lcd_write_string("Light: ");
        display_integer(simulated_lux);
        lcd_write_string(" Lux");
        
        lcd_delay(1500);
        simulated_temp = (simulated_temp >= 35) ? 20 : simulated_temp + 1;
        simulated_lux  = (simulated_lux >= 900) ? 200 : simulated_lux + 25;
    }
}
