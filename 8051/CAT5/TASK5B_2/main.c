/*
 * Experiment: CAT5 - Task 5B.2: Precision Pulse Generation
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include <reg51.h>

sbit PULSE_OUT = P1^0;

volatile unsigned int pulse_tick = 0;

void init_timer0_pulse(void) {
    TMOD = (TMOD & 0xF0) | 0x02;
    TH0 = 256 - 230;
    TL0 = 256 - 230;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}

void timer0_isr(void) interrupt 1 {
    pulse_tick++;
    if (pulse_tick >= 2) {
        pulse_tick = 0;
        PULSE_OUT = ~PULSE_OUT;
    }
}

void main(void) {
    PULSE_OUT = 0;
    init_timer0_pulse();
    while (1);
}
