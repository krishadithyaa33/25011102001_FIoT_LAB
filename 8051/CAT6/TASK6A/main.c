/*
 * Experiment: CAT6 - Task 6A: 8051 UART Initialization & String Transmission
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: 9600 baud serial character transmission via Timer 1 Mode 2.
 * Microcontroller: AT89S52 (11.0592 MHz)
 */

#include <reg51.h>

void uart_init_9600(void) {
    TMOD = (TMOD & 0x0F) | 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
    TI = 1;
}

void uart_send_char(char ch) {
    while (!TI);
    TI = 0;
    SBUF = ch;
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

void delay_ms(unsigned int ms) {
    unsigned int a, b;
    for (a = 0; a < ms; a++) {
        for (b = 0; b < 120; b++);
    }
}

void main(void) {
    uart_init_9600();
    
    while (1) {
        uart_send_string("FIoT 8051 UART Ready [Krish Adithyaa - 25011102001]\r\n");
        delay_ms(1000);
    }
}
