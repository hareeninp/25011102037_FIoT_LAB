# CONTINUOUS LAB EVALUATION 10

**DATE:** 05/10/2026

**NAME OF EXP:** STM32–Wemos Wi-Fi Modem Interface Using AT Commands

**HARDWARE SETUP / PLATFORM:** STM32 Development Board + Wemos D1 Mini (ESP8266) + STM32CubeMX + Keil MDK

## EXPERIMENT OVERVIEW

Interface an STM32 development board with a Wemos D1 Mini (ESP8266) through UART, configure the Wi-Fi modem using AT commands, acquire sensor data through the STM32, and transmit the sensor data over a Wi-Fi network.

## TASKS

**Task 9A — Establish STM32 ↔ Wemos UART Communication**

Establish UART communication between STM32 and Wemos, transmit `AT\r\n`, and receive the modem response.

**Task 9B — Explore the ESP8266 AT Command Interface**

Investigate ESP8266 AT commands for checking modem response, identifying firmware information, configuring Wi-Fi station mode, and scanning available networks.

## HARDWARE CONNECTIONS

| Wemos D1 Mini | STM32 |
|---|---|
| TX | RX |
| RX | TX |
| GND | GND |
| 5V / 3.3V | Appropriate power source |

## DEVELOPMENT TOOLS

- STM32CubeMX
- Keil MDK
- STM32 HAL Libraries
- UART Serial Terminal
- Wemos D1 Mini (ESP8266)