# STM32 ARM Cortex-M Laboratory Experiments

**Platforms:** 
- STMicroelectronics STM32F103C8T6 (ARM Cortex-M3 @ 72 MHz, Blue Pill)
- STMicroelectronics STM32F401RETx (ARM Cortex-M4 @ 84 MHz, Nucleo-64)
- Espressif Systems ESP8266 (Wemos D1 Mini / ESP-12F Wi-Fi SoC)  
**IDEs & Toolchain:** STM32CubeMX + Keil MDK-ARM v5.xx  
**Middleware & Tools:** Node-RED, Mosquitto MQTT Broker, OpenWeatherMap REST API  
**Student:** Krish Adithyaa (Roll No: 25011102001)  

---

## Overview

This directory contains the complete set of embedded IoT experiments developed on **STM32 32-bit ARM Cortex-M** microcontrollers using the official STM32Cube Hardware Abstraction Layer (HAL).

### Experiment Index

| Folder | Experiment Name | Focus Areas |
|---|---|---|
| [CAT8](./CAT8) | STM32 GPIO Bring-Up & Switch Debouncing | Blinky on PC13, event-driven switch debouncing, press-duration classifier |
| [CAT9](./CAT9) | STM32 UART Communication & Command Interface | USART1 echo at 115200 baud, string command interpreter (`LED ON/OFF/TOGGLE`) |
| [CAT10](./CAT10) | STM32 ↔ Wemos ESP8266 Hardware Bridge & AT Interfacing | Dual-UART bridge link, AT command parser, automated Wi-Fi connection |
| [CAT11](./CAT11) | Embedded TCP Web Server & HTTP Telemetry | Standalone embedded HTTP server, Node-RED REST client polling |
| [CAT12](./CAT12) | STM32 Nucleo-F401RE Hardware Architecture Bring-Up | Nucleo green LED (PA5), blue button (PC13) latching memory & duration classifier |
| [CAT13](./CAT13) | BME280 Environmental Sensor & HTTP Analytics | I2C sensor acquisition, ESP8266 HTTP GET telemetry, Node-RED dashboard |
| [CAT14](./CAT14) | MQTT Telemetry Pipeline | BME280 environmental telemetry publish to MQTT broker & Node-RED display |
| [CAT15](./CAT15) | Real-Time Environmental Sensing & OpenWeather Comparison | Live BME280 data vs. OpenWeather API ground truth & predictive dashboard |
