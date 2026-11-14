# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5 (CAT5)

**DATE:** 10/08/2026

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing for LED Fading, Pulse Generation, and Stepper Motor Control

**HARDWARE SETUP / PLATFORM:** AT89S52 (11.0592 MHz) + Keil C51 µVision

---

## TASK 5B : Hardware Timer Pulse Generation

### 1. Circuit Diagram

The circuit connects the signal output pin P1.0 to an indicator LED or oscilloscope test probe.

- **Microcontroller:** AT89S52
- **Output Pin:** P1.0
- **Peripheral:** LED with current limiter / Oscilloscope test point
- **Operating Voltage:** +5V DC

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

Timer 0 configured in 8-bit auto-reload Mode 2 (`TMOD = 0x02`) generates high-frequency hardware interrupt ticks without software reload overhead. The ISR generates a software Pulse Width Modulation (PWM) signal by adjusting duty cycle steps or toggling output states at calibrated frequencies.

### 3. Inference

Mode 2 auto-reload eliminates jitter associated with software reload latencies, producing clean, stable waveforms verified on hardware indicators and test probes.
