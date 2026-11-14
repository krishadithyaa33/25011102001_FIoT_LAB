/*
 * Experiment: CAT5 - Task 5B.3: Variable Frequency Multi-Speed Waveforms
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include <reg51.h>

sbit WAVE_PIN = P1^0;

volatile unsigned char wave_state = 0;

void init_timer0_variable(void) {
    TMOD = (TMOD & 0xF0) | 0x02;
    TH0 = 256 - 115;
    TL0 = 256 - 115;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}

void timer0_isr(void) interrupt 1 {
    wave_state++;
    if (wave_state >= 8) {
        wave_state = 0;
        WAVE_PIN = ~WAVE_PIN;
    }
}

void main(void) {
    WAVE_PIN = 0;
    init_timer0_variable();
    while (1);
}
