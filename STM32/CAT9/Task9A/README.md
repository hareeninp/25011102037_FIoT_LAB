# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 9

**NAME OF EXP:** Basic UART Communication 

**HARDWARE SETUP / PLATFORM:** STM32CubeMX + Keil MDK + STM32 Development Board Blue Pill STM32F103C8T6

---

## TASK 9A – UART Communication

### 1. Circuit Diagram

The experiment demonstrates UART serial communication using the USART1 peripheral of the STM32 Blue Pill development board.

**Hardware Components:**
- **Development Board:** STM32 Blue Pill
- **Microcontroller IC:** STM32F103C8T6
- **UART Peripheral:** USART1
- **TX Pin:** PA9 (USART1_TX)
- **RX Pin:** PA10 (USART1_RX)
- **Communication Interface:** USB-to-TTL Serial Converter

**Connections:**
- STM32 PA9 (TX) → USB-to-TTL RX
- STM32 PA10 (RX) → USB-to-TTL TX
- STM32 GND → USB-to-TTL GND

**UART Configuration:**
- Baud Rate: 115200
- Word Length: 8 Bits
- Stop Bits: 1
- Parity: None
- Mode: Transmitter and Receiver

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates UART communication using the STM32 HAL library. USART1 is configured in transmit and receive mode with a baud rate of 115200.

The microcontroller continuously receives a character through the UART receiver (RX). After receiving the character, it introduces a delay of 1 second and transmits the same character back through the UART transmitter (TX). Another delay of 1 second is introduced before repeating the process.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO pins.
4. Initialize USART1 with a baud rate of 115200.
5. Declare a variable to store the received character.
6. Wait until a character is received through UART.
7. Introduce a delay of 1 second.
8. Transmit the received character through UART.
9. Introduce another delay of 1 second.
10. Repeat the process continuously.

**Code Base:**

The UART communication operations are performed using the following STM32 HAL functions:

- `HAL_UART_Init()` – Initializes the USART peripheral.
- `HAL_UART_Receive()` – Receives data through UART.
- `HAL_UART_Transmit()` – Transmits data through UART.
- `HAL_Delay()` – Introduces time delays.
- `HAL_Init()` – Initializes the HAL library.

The `HAL_MAX_DELAY` parameter makes the receive and transmit operations wait until completion or an error occurs.

### 3. Inference

The STM32 Blue Pill successfully receives a character through USART1 and transmits the same character back after a delay of 1 second.

This experiment demonstrates basic UART serial communication, character reception, data transmission, and the use of STM32 HAL UART functions.
