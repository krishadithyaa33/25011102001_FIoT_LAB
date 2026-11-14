/*
 * Experiment: CAT1 - 8051 Development Board Tool Chain Setup
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: Bare-metal LED blinking using Port 1 Pin 0 (P1.0).
 * Microcontroller: AT89S52 (11.0592 MHz crystal)
 */

#include <reg51.h>

/* Pin definition for active-high or active-low LED output */
sbit BLINK_LED = P1^0;

/* Software delay routine using nested counting loops */
void delay_cycles(unsigned int count) {
    unsigned int outer, inner;
    for (outer = 0; outer < count; outer++) {
        for (inner = 0; inner < 120; inner++) {
            /* NOP delay: approx 1 ms per count at 11.0592 MHz */
        }
    }
}

void main(void) {
    /* Initialize pin state */
    BLINK_LED = 0;
    
    while (1) {
        BLINK_LED = 1;          /* Drive LED pin HIGH */
        delay_cycles(500);      /* 500 ms active time */
        BLINK_LED = 0;          /* Drive LED pin LOW */
        delay_cycles(500);      /* 500 ms idle time */
    }
}
