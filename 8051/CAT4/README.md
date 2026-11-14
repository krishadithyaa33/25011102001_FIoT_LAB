# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESMENT 4

**DATE:** 03/08/2026

**NAME OF EXP:** 8051 Matrix Keypad, Seven-Segment Display and LED Interfacing

**HARDWARE SETUP / PLATFORM:** AT89S52 Microcontroller + 4x4 Matrix Keypad + Common-Cathode 7-Segment Display

---

## TASK 4A : Matrix Keypad Row-Column Strobe & Display Decoding

### 1. Circuit Diagram

The circuit interfaces a 4x4 matrix keypad to Port 2, a common-cathode 7-segment display to Port 0 (via pull-up resistor array), and status LEDs to Port 1.

- **Microcontroller:** AT89S52 (8051 Architecture)
- **Keypad Rows:** P2.4, P2.5, P2.6, P2.7 (Output strobe lines)
- **Keypad Columns:** P2.0, P2.1, P2.2, P2.3 (Input sense lines with pull-ups)
- **7-Segment Bus:** Port 0 with 10 kΩ pull-up network
- **Status Output:** Port 1 (P1.0–P1.3)
- **Power Supply:** +5V DC

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

A 4x4 matrix keypad multiplexes 16 push-buttons onto 8 microcontroller pins through a grid of rows and columns. The algorithm drives one row LOW at a time while reading the column sensing inputs. If a button at the intersection of active row $R$ and column $C$ is closed, column line $C$ is pulled LOW. The corresponding character is mapped from a $4\times 4$ lookup matrix, debounced, and decoded into segment activation patterns on Port 0.

### 3. Inference

Matrix scanning reduced pin count from 16 discrete lines down to 8 shared GPIO pins. The 7-segment display reliably reflected numeric button entries while Port 1 confirmed accurate binary decoding.
