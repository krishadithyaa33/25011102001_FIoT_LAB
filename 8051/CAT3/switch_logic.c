/*
 * Supplementary Switch-to-LED Direct Logic
 * File: switch_logic.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 */

#include <reg51.h>

sbit SW_PIN  = P2^0;
sbit LED_PIN = P1^0;

void main(void) {
    SW_PIN = 1;   /* Configure switch pin as input */
    LED_PIN = 0;  /* Turn OFF LED initially */
    
    while (1) {
        if (SW_PIN == 0) {
            LED_PIN = 1;  /* Turn ON when pressed */
        } else {
            LED_PIN = 0;  /* Turn OFF when released */
        }
    }
}
