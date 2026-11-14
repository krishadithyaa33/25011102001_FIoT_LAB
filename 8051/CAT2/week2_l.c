/*
 * Experiment: CAT2 - Bare-Metal LED Blink & Calibrated Delay
 * File: week2_l.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: Precision software delay generation for 8051 LED blink.
 * Microcontroller: AT89S52 (11.0592 MHz Crystal Oscillator)
 */

#include <reg51.h>

/* Port 1 Bit 0 connected to active-high indicator LED */
sbit STATUS_LED = P1^0;

/*
 * Calibrated software delay routine for 11.0592 MHz crystal.
 * Each 8051 machine cycle = 12 clock periods = 1.085 us.
 * 120 inner iterations provide approximately 1 millisecond.
 */
void delay_ms(unsigned int duration_ms) {
    unsigned int iter_i;
    unsigned char iter_j;
    for (iter_i = 0; iter_i < duration_ms; iter_i++) {
        for (iter_j = 0; iter_j < 120; iter_j++) {
            /* Execute empty loop body */
        }
    }
}

void main(void) {
    /* Initialize LED state */
    STATUS_LED = 0;
    
    while (1) {
        STATUS_LED = ~STATUS_LED;   /* Invert output state */
        delay_ms(500);              /* Maintain state for 500 ms */
    }
}
