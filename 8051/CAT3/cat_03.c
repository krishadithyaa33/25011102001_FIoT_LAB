/*
 * Experiment: CAT3 - LED Pattern Generator & Button Controller
 * File: cat_03.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: 4-mode sequential LED state machine driven by a debounced push button.
 * Microcontroller: AT89S52 (11.0592 MHz)
 */

#include <reg51.h>

/* Button input on Port 2 Pin 6 (Active-LOW) */
sbit BTN_INPUT = P2^6;

/* Operating mode tracking variable */
unsigned char active_mode = 0;

/* Software millisecond delay */
void delay_ms(unsigned int ms) {
    unsigned int idx_i;
    unsigned char idx_j;
    for (idx_i = 0; idx_i < ms; idx_i++) {
        for (idx_j = 0; idx_j < 127; idx_j++) {
            /* 1 ms tick delay */
        }
    }
}

/* Software debouncing routine for active-LOW tactile button */
unsigned char check_button_press(void) {
    if (BTN_INPUT == 0) {
        delay_ms(25);              /* 25 ms debounce delay */
        if (BTN_INPUT == 0) {
            while (BTN_INPUT == 0);/* Wait until button release */
            delay_ms(25);          /* Release debounce */
            return 1;              /* Valid transition detected */
        }
    }
    return 0;
}

/* Mode 1: Sequential running LEDs (P1.0 -> P1.1 -> P1.2 -> P1.3) */
void execute_running_led(void) {
    unsigned char step;
    for (step = 0; step < 4; step++) {
        P1 = ~(1 << step);
        delay_ms(200);
        if (check_button_press()) { active_mode = 1; return; }
    }
}

/* Mode 2: 4-bit Binary Up-Counter (0000 to 1111) */
void execute_binary_counter(void) {
    unsigned char count;
    for (count = 0; count < 16; count++) {
        P1 = ~count;
        delay_ms(250);
        if (check_button_press()) { active_mode = 2; return; }
    }
}

/* Mode 3: Alternating Pattern (1010 <-> 0101) */
void execute_alternating_pattern(void) {
    P1 = ~0x0A;
    delay_ms(300);
    if (check_button_press()) { active_mode = 3; return; }
    P1 = ~0x05;
    delay_ms(300);
    if (check_button_press()) { active_mode = 3; return; }
}

/* Mode 4: All LEDs flashing simultaneously */
void execute_flash_pattern(void) {
    P1 = ~0x0F;
    delay_ms(250);
    if (check_button_press()) { active_mode = 0; return; }
    P1 = ~0x00;
    delay_ms(250);
    if (check_button_press()) { active_mode = 0; return; }
}

void main(void) {
    /* Initialize button pin as input with pull-up */
    BTN_INPUT = 1;
    P1 = 0xFF;  /* Extinguish all LEDs initially */

    while (1) {
        if (check_button_press()) {
            active_mode = (active_mode + 1) % 4;
        }

        switch (active_mode) {
            case 0: execute_running_led(); break;
            case 1: execute_binary_counter(); break;
            case 2: execute_alternating_pattern(); break;
            case 3: execute_flash_pattern(); break;
            default: active_mode = 0; break;
        }
    }
}
