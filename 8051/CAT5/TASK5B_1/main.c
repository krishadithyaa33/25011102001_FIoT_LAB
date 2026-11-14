/*
 * Experiment: CAT5 - Task 5B.1: PWM LED Fading using Timer 0 Mode 2
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include <reg51.h>

sbit FADE_LED = P1^0;

volatile unsigned char pwm_cycle_counter = 0;
volatile unsigned char active_duty_cycle = 0;
volatile unsigned int fade_step_timer = 0;
bit sweep_direction_up = 1;

void setup_timer0_pwm(void) {
    TMOD = (TMOD & 0xF0) | 0x02;
    TH0 = 256 - 92;
    TL0 = 256 - 92;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}

void timer0_isr(void) interrupt 1 {
    pwm_cycle_counter++;
    if (pwm_cycle_counter >= 20) {
        pwm_cycle_counter = 0;
    }
    
    FADE_LED = (pwm_cycle_counter < active_duty_cycle) ? 1 : 0;
    
    fade_step_timer++;
    if (fade_step_timer >= 400) {
        fade_step_timer = 0;
        if (sweep_direction_up) {
            active_duty_cycle++;
            if (active_duty_cycle >= 20) sweep_direction_up = 0;
        } else {
            if (active_duty_cycle > 0) active_duty_cycle--;
            if (active_duty_cycle == 0) sweep_direction_up = 1;
        }
    }
}

void main(void) {
    FADE_LED = 0;
    setup_timer0_pwm();
    while (1);
}
