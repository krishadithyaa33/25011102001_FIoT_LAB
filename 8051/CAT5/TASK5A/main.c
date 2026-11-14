/*
 * Experiment: CAT5 - Task 5A: 1-Second Hardware Timer Interrupt
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: 8051 Timer 0 Mode 1 (16-bit) interrupt-driven 1-second LED toggle.
 * Microcontroller: AT89S52 (11.0592 MHz)
 */

#include <reg51.h>

sbit TIMER_LED = P1^0;

volatile unsigned int millisecond_counter = 0;

void configure_timer0_1ms(void) {
    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}

void timer0_isr(void) interrupt 1 {
    TH0 = 0xFC;
    TL0 = 0x66;
    
    millisecond_counter++;
    if (millisecond_counter >= 1000) {
        millisecond_counter = 0;
        TIMER_LED = ~TIMER_LED;
    }
}

void main(void) {
    TIMER_LED = 0;
    configure_timer0_1ms();
    while (1);
}
