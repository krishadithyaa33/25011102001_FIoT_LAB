/*
 * Experiment: CAT4 - Matrix Keypad, 7-Segment Display & LED Interfacing
 * File: week4_logic.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: Scanning a 4x4 matrix keypad and rendering the active digit
 *              onto a common-cathode 7-segment display on Port 0.
 * Microcontroller: AT89S52 (11.0592 MHz)
 */

#include <reg51.h>

#define KEYPAD_PORT P2
#define SEG_PORT    P0
#define LED_PORT    P1

code unsigned char digit_patterns[10] = {
    0x3F, /* 0 */
    0x06, /* 1 */
    0x5B, /* 2 */
    0x4F, /* 3 */
    0x66, /* 4 */
    0x6D, /* 5 */
    0x7D, /* 6 */
    0x07, /* 7 */
    0x7F, /* 8 */
    0x6F  /* 9 */
};

void delay_ms(unsigned int ms) {
    unsigned int x, y;
    for (x = 0; x < ms; x++) {
        for (y = 0; y < 120; y++);
    }
}

unsigned char scan_keypad(void) {
    unsigned char row, col;
    unsigned char keypad_matrix[4][4] = {
        { 1,  2,  3, 0xA},
        { 4,  5,  6, 0xB},
        { 7,  8,  9, 0xC},
        {0xE, 0, 0xF, 0xD}
    };

    for (row = 0; row < 4; row++) {
        KEYPAD_PORT = ~(1 << (row + 4)) | 0x0F;
        for (col = 0; col < 4; col++) {
            if ((KEYPAD_PORT & (1 << col)) == 0) {
                delay_ms(20);
                if ((KEYPAD_PORT & (1 << col)) == 0) {
                    while ((KEYPAD_PORT & (1 << col)) == 0);
                    return keypad_matrix[row][col];
                }
            }
        }
    }
    return 0xFF;
}

void main(void) {
    unsigned char detected_key = 0;
    SEG_PORT = digit_patterns[0];
    LED_PORT = 0x00;

    while (1) {
        detected_key = scan_keypad();
        if (detected_key != 0xFF) {
            if (detected_key <= 9) {
                SEG_PORT = digit_patterns[detected_key];
                LED_PORT = detected_key;
            } else {
                LED_PORT = 0xFF;
                delay_ms(150);
                LED_PORT = 0x00;
            }
        }
    }
}
