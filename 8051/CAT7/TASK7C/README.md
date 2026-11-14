# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 7 (CAT7)

**DATE:** 24/08/2026

**NAME OF EXP:** LCD Interfacing and Display Control

**HARDWARE SETUP / PLATFORM:** AT89S52 (11.0592 MHz) + HD44780 16x2 Alphanumeric LCD Module

---

## TASK 7C : Dynamic Sensor Data Formatting

### 1. Circuit Diagram

The circuit interfaces an industry-standard HD44780-compatible 16x2 alphanumeric LCD display to 8051 Port 0 and control lines on Port 2.

- **Microcontroller:** AT89S52 (8051 Architecture)
- **Data Bus (D0–D7):** Port 0 (P0.0 to P0.7) with external 10 kΩ pull-up network
- **Register Select (RS):** P2.0 (0=Command register, 1=Data register)
- **Read/Write (RW):** P2.1 (0=Write mode, 1=Read mode)
- **Enable Strobe (EN):** P2.2 (High-to-Low transition latch)
- **Contrast Adjustment:** 10 kΩ potentiometer to pin V0
- **Power Supply:** +5V DC

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The HD44780 display controller features an 8-bit parallel interface and internal DDRAM (Display Data RAM). Initialization requires sending function set command `0x38` (8-bit bus, 2 display lines, $5\times 8$ font matrix), followed by `0x0C` (display on, cursor off), `0x06` (entry mode increment), and `0x01` (clear display). Timing between consecutive command assertions is strictly governed by microsecond hold and settle delays across enable line P2.2.

### 3. Inference

The 16x2 alphanumeric LCD driver successfully rendered character graphics and dynamic numerical sensor fields with clear contrast and zero visual artifacting, establishing a solid HMI output mechanism for 8051 embedded applications.
