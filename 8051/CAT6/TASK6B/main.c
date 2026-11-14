/*
 * Experiment: CAT6 - Task 6B: UART Driver and Serial Debugging Echo
 * File: main.c
 * Student: Krish Adithyaa (Roll No: 25011102001)
 * Description: Full-duplex character echo and LED status acknowledgment.
 * Microcontroller: AT89S52 (11.0592 MHz)
 */

#include <reg51.h>

sbit RX_INDICATOR = P1^0;

void uart_init_9600(void) {
    TMOD = (TMOD & 0x0F) | 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}

void uart_send_char(char c) {
    while (!TI);
    TI = 0;
    SBUF = c;
}

char uart_receive_char(void) {
    while (!RI);
    RI = 0;
    return SBUF;
}

void uart_send_string(const char *s) {
    while (*s) {
        uart_send_char(*s++);
    }
}

void main(void) {
    char received_byte;
    RX_INDICATOR = 0;
    
    uart_init_9600();
    uart_send_string("8051 Serial Echo Terminal Initialized\r\n");

    while (1) {
        received_byte = uart_receive_char();
        RX_INDICATOR = ~RX_INDICATOR;
        uart_send_string("Echo: ");
        uart_send_char(received_byte);
        uart_send_string("\r\n");
    }
}
