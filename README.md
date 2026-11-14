# Foundations of IoT (FIoT) – Laboratory Experiments Repository

**Student Name:** Krish Adithyaa  
**Roll Number:** 25011102001  
**GitHub Username:** [krishadithyaa33](https://github.com/krishadithyaa33)  
**Course:** 25CS2741 – Foundations of Internet of Things + Lab  
**Academic Year:** 2026–2027  

---

## 1. About This Repository

This repository contains the complete laboratory submissions, source codes, project configuration files, circuit schematics, and comprehensive technical documentation for the **Foundations of Internet of Things (FIoT)** course.

All experiments are structured systematically according to target hardware architectures:
- **8051 Microcontroller (AT89S52):** Hardware bring-up, bare-metal GPIO register operations, timer configuration, PWM generation, stepper motor sequencing, UART serial interfaces, and 16x2 alphanumeric LCD drivers.
- **STM32 Microcontrollers (STM32F103C8T6 Blue Pill & STM32F401RETx Nucleo):** ARM Cortex-M architecture initialization via STM32CubeMX HAL, event-driven switch debouncing, state machines, dual-UART bridge interfaces, ESP8266 AT firmware communication, TCP web servers, REST API telemetry, MQTT publishing, and Node-RED cloud analytics.

---

## 2. Directory Structure

```text
25011102001_FIoT_LAB/
│
├── .gitignore
├── README.md
├── FINAL_AUDIT_REPORT.txt
│
├── 8051/
│   ├── README.md
│   ├── CAT1/       # 8051 Development Board Tool Chain Setup & LED Blink
│   ├── CAT2/       # Bare-Metal LED Blink & Precision Software Delay
│   ├── CAT3/       # Timer-Based LED Pattern Generator & Switch Logic Controller
│   ├── CAT4/       # 4x4 Matrix Keypad, 7-Segment Display & LED Multiplexing
│   ├── CAT5/       # Hardware Timers, PWM Fading, Pulse Generation & Stepper Motor
│   │   ├── TASK5A/     # 1-Second Timer0 Interrupt Generator
│   │   ├── TASK5B_1/   # Software PWM LED Breathing / Fading
│   │   ├── TASK5B_2/   # Hardware Timer Square Wave Pulse Generator
│   │   ├── TASK5B_3/   # Variable Frequency Multi-Speed Waveform Controller
│   │   └── TASK5C/     # 4-Phase Stepper Motor ULN2003 Driver Controller
│   ├── CAT6/       # Serial Communication (UART) & Driver Architecture
│   │   ├── TASK6A/     # UART 9600 Baud Initialization & Character Transmission
│   │   └── TASK6B/     # UART Full-Duplex Echo & Serial Command Parser
│   └── CAT7/       # 16x2 Alphanumeric LCD Display Interfacing
│       ├── TASK7A/     # 8-Bit LCD Initialization & Static String Display
│       ├── TASK7B/     # LCD Shift Functions & Custom Character Generation
│       └── TASK7C/     # Dynamic Integer Sensor Data Formatting & Display
│
└── STM32/
    ├── README.md
    ├── CAT8/       # STM32 GPIO Bring-Up & Switch Debounce State Logic
    │   ├── TASK8A/     # Onboard LED Blinky (PC13)
    │   ├── TASK8B/     # Event-Based Control & Software Switch Debouncing
    │   └── TASK8C/     # Short-Press vs. Long-Press Duration Classifier
    ├── CAT9/       # STM32 UART Communication & Command Interface
    │   ├── TASK9A/     # USART1 115200 Baud Character Echo & Banner Transmission
    │   └── TASK9B/     # Text Command Parser (LED ON / LED OFF / LED TOGGLE)
    ├── CAT10/      # STM32 ↔ Wemos ESP8266 Hardware Bridge & AT Interfacing
    │   ├── TASK10A/    # Dual UART Bridge Link (STM32 ↔ ESP8266 ↔ PC)
    │   ├── TASK10B/    # ESP8266 AT Command Diagnostics & Firmware Query
    │   └── TASK10C/    # Automated Station Mode Wi-Fi Connection
    ├── CAT11/      # Embedded TCP Web Server & HTTP Telemetry
    │   ├── TASK11A/    # Standalone Embedded HTTP Server (Static HTML Response)
    │   └── TASK11B/    # Node-RED HTTP Client Integration (JSON Telemetry API)
    ├── CAT12/      # STM32 Nucleo-F401RE Hardware Architecture Bring-Up
    │   ├── TASK12A/    # Nucleo User LED (PA5) Bring-Up & Register Control
    │   ├── TASK12B/    # User Button (PC13) State Memory & Latching Logic
    │   └── TASK12C/    # Multi-Function Button Classifier (Short vs. Long Press)
    ├── CAT13/      # BME280 Environmental Sensor & HTTP Analytics
    │   └── TASK13/     # I2C Telemetry Pipeline → ESP8266 HTTP → Node-RED
    ├── CAT14/      # MQTT Telemetry Pipeline
    │   └── TASK14/     # BME280 Publish to MQTT Broker → Node-RED Dashboard
    └── CAT15/      # Real-Time Environmental Sensing & OpenWeather Comparison
        └── TASK15/     # BME280 Local Sensing vs. OpenWeather API & Predictive Dashboard
```

---

## 3. Toolchain & Development Environment

- **Microcontrollers:**
  - Microchip / Atmel AT89S52 (8-bit 8051, 11.0592 MHz Crystal, 40-pin DIP)
  - STMicroelectronics STM32F103C8T6 (ARM Cortex-M3, 72 MHz, Blue Pill)
  - STMicroelectronics STM32F401RETx (ARM Cortex-M4, 84 MHz, Nucleo-64)
  - Espressif ESP8266 (Wemos D1 Mini / ESP-12F Wi-Fi SoC)
- **IDEs & Compilers:**
  - Keil µVision C51 v5.xx (8051 Embedded C Compiler)
  - Keil MDK-ARM v5.xx (ARM Cortex-M Compiler & Debugger)
  - STM32CubeMX (HAL code generation and pin multiplexing)
- **Middleware & Cloud Services:**
  - Node-RED (Flow-based IoT visual orchestration and dashboard UI)
  - Mosquitto MQTT Broker (Lightweight publish/subscribe telemetry messaging)
  - OpenWeatherMap REST API (Meteorological ground-truth comparison)

---

## 4. Hardware Safety & Best Practices

1. All GPIO lines interfacing active loads (LEDs, buzzers) utilize suitable current-limiting resistors (220 Ω – 1 kΩ).
2. High-current inductive loads (stepper motors) are driven via a ULN2003 Darlington transistor array with reverse-EMF clamping diodes.
3. Level-matching considerations are observed when interconnecting 5V 8051 / peripheral logic with 3.3V STM32 / ESP8266 modules.
4. Non-blocking state architectures (`HAL_GetTick()` and timer ISRs) are favored over blocking delay loops to preserve real-time responsiveness.
