# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESMENT 2

**DATE:** 20/07/2026

**NAME OF EXP:** 8051 Tool Chain Setup and Bare-Metal LED Blink

**HARDWARE SETUP / PLATFORM:** AT89S52 Development Board + Keil µVision C51

---

## TASK 2A : Bare-Metal LED Blink with Custom Delay Library

### 1. Circuit Diagram

The circuit interfaces an indicator LED to pin P1.0 of the AT89S52 8051 microcontroller.

- **Microcontroller:** AT89S52 (8051 Architecture)
- **Clock Frequency:** 11.0592 MHz Crystal Oscillator
- **GPIO Port:** Port 1
- **GPIO Pin:** P1.0
- **Peripheral:** 5mm Red LED with 330 Ω series resistor
- **Supply Voltage:** +5V DC

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The AT89S52 executes instructions based on machine cycles comprising 12 oscillator clock periods. At an oscillator frequency of 11.0592 MHz, one machine cycle equals $1.0851\,\mu\text{s}$. A modular delay function `delay_ms(unsigned int ms)` utilizes calibrated nested loops to generate accurate timing intervals without dedicated hardware timers. Port pin P1.0 is periodically inverted using the bitwise NOT operator (`~STATUS_LED`).

**Pseudocode:**

1. Include register definitions `<reg51.h>`.
2. Map `STATUS_LED` to pin P1.0.
3. Implement `delay_ms(unsigned int duration_ms)`:
   - Outer loop iterates from $0$ to `duration_ms - 1`.
   - Inner loop runs $120$ iterations consuming roughly $1\,\text{ms}$ total instruction time.
4. In `main()`:
   - Invert `STATUS_LED` state on every cycle (`STATUS_LED = ~STATUS_LED`).
   - Call `delay_ms(500)` to introduce a 0.5-second interval.
5. Continuously execute inside an infinite loop.

**Code Base:**

- `STATUS_LED = P1^0`: Direct bit-addressable SFR definition.
- `STATUS_LED = ~STATUS_LED`: Toggles output between logic 1 (HIGH) and logic 0 (LOW).
- `delay_ms(500)`: Suspends execution for approximately 500 milliseconds.

### 3. Inference

The experiment confirmed accurate software timing calculations on the AT89S52 development board. The LED on P1.0 toggles at a steady 1 Hz frequency (500 ms ON, 500 ms OFF), establishing a reliable foundation for register-level digital output control.
