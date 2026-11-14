/*
 * Experiment: CAT5 - Task 5C: 4-Phase Stepper Motor ULN2003 Driver Control
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: Stepper motor wave drive & half-step sequence with direction control.
 * Microcontroller: AT89S52 (11.0592 MHz)
 */

#include <reg51.h>

#define MOTOR_PORT P1
sbit DIR_SWITCH = P2^0;

code unsigned char wave_drive_sequence[4] = {
    0x01, /* 0001: Coil A */
    0x02, /* 0010: Coil B */
    0x04, /* 0100: Coil C */
    0x08  /* 1000: Coil D */
};

void motor_delay(unsigned int ms) {
    unsigned int p, q;
    for (p = 0; p < ms; p++) {
        for (q = 0; q < 120; q++);
    }
}

void main(void) {
    char step_idx = 0;
    DIR_SWITCH = 1;

    while (1) {
        MOTOR_PORT = wave_drive_sequence[step_idx];
        motor_delay(15);
        
        if (DIR_SWITCH == 1) {
            step_idx++;
            if (step_idx >= 4) step_idx = 0;
        } else {
            step_idx--;
            if (step_idx < 0) step_idx = 3;
        }
    }
}
