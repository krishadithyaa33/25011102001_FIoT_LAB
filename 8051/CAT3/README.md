# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESMENT 3

**DATE:** 27/07/2026

**NAME OF EXP:** Timer-Based LED Pattern Generator and Button Interrupt Controller

**HARDWARE SETUP / PLATFORM:** AT89S52 Microcontroller Development Board + Push-Button + 4-LED Array

---

## TASK 3A : 4-Mode LED Pattern Controller with Switch Debouncing

### 1. Circuit Diagram

The circuit interfaces four LEDs to Port 1 (P1.0–P1.3) and a push-button to Port 2 Pin 6 (P2.6).

- **Microcontroller:** AT89S52 (8051 Architecture)
- **Clock Frequency:** 11.0592 MHz
- **Input Pin:** P2.6 configured with internal pull-up as active-LOW button
- **Output Pins:** P1.0, P1.1, P1.2, P1.3 driving four LEDs via 330 Ω current limiters
- **Power Supply:** +5V DC

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

Mechanical push-buttons suffer from contact bounce, generating spurious false transitions during the initial $10\text{–}20\,\text{ms}$ of contact closure. A robust software debouncing algorithm samples the input pin, verifies stability across a 25 ms delay window, and awaits physical release before committing state changes. Each confirmed button event advances a finite state machine through four operational modes:
1. **Running Chaser:** LEDs illuminate sequentially in a single-bit rolling pattern.
2. **Binary Up-Counter:** Displays a 4-bit binary progression ($0000_2$ to $1111_2$).
3. **Alternating Flasher:** Toggles odd and even bits ($1010_2 \leftrightarrow 0101_2$).
4. **All-LED Strobe:** Synchronously flashes all four LEDs ($1111_2 \leftrightarrow 0000_2$).

**Pseudocode:**

1. Initialize P2.6 as digital input (`BTN_INPUT = 1`).
2. Set initial state: `active_mode = 0`, LEDs OFF (`P1 = 0xFF`).
3. Check button status:
   - If pin LOW, wait 25 ms and re-sample.
   - If confirmed LOW, block until pin returns HIGH, then return 1.
4. Execute corresponding pattern using `switch(active_mode)`.
5. Interleave button polling between pattern frame delays to ensure responsive mode transitions.

**Code Base:**

- `check_button_press()`: Handles debouncing and release detection.
- `P1 = ~(1 << step)`: Computes active-low bit-shifting pattern for running LEDs.
- `P1 = ~count`: Inverts binary count for common-anode or active-low LED wiring.

### 3. Inference

The state machine transitioned seamlessly across all four visual modes without missed presses or multi-trigger glitches. Software debouncing successfully eliminated mechanical switch bounce artifacts, validating event-driven GPIO control on the 8051 architecture.
