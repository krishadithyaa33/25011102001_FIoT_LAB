# 8051 Microcontroller Laboratory Experiments

**Platform:** AT89S52 (8051 Architecture, 40-Pin DIP, 11.0592 MHz Crystal)  
**IDE & Toolchain:** Keil µVision C51 v5.xx  
**Student:** Krish Adithyaa (Roll No: 25011102001)  

---

## Overview

This directory contains the complete set of laboratory experiments conducted on the **Intel 8051 / Atmel AT89S52** microcontroller platform. All code is written in bare-metal Embedded C with direct Special Function Register (SFR) manipulation.

### Experiment Index

| Folder | Experiment Name | Focus Areas |
|---|---|---|
| [CAT1](./CAT1) | 8051 Development Board Tool Chain Setup | Keil C51 environment, bare-metal GPIO toggle, delay loop |
| [CAT2](./CAT2) | 8051 Tool Chain Setup & Bare-Metal LED Blink | Precision software millisecond delay, register control |
| [CAT3](./CAT3) | Timer-Based LED Pattern Generator & Switch Logic | 4-mode LED state machine, active-low button debouncing |
| [CAT4](./CAT4) | Matrix Keypad, 7-Segment Display & LED Interfacing | 4x4 matrix key scanning, common-cathode 7-segment decoder |
| [CAT5](./CAT5) | Hardware Timers, PWM Generation & Stepper Motor | Timer0 Mode 1 ISR, Timer0 Mode 2 PWM breathing, pulse generation, ULN2003 stepper motor |
| [CAT6](./CAT6) | UART Driver Architecture & Serial Debugging | 9600 baud serial TX/RX, Timer 1 Mode 2 baud generator, echo |
| [CAT7](./CAT7) | 16x2 Alphanumeric LCD Display Interfacing | 8-bit parallel LCD interface, custom characters, dynamic sensor formatting |
