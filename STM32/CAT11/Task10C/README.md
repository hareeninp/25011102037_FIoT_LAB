# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 11

**NAME OF EXP:** STM32–ESP8266 Wi-Fi Configuration and TCP Server Setup using AT Commands

**HARDWARE SETUP / PLATFORM:** STM32CubeMX + Keil MDK + STM32F401RE Development Board + Wemos ESP8266 Wi-Fi Module

---

## TASK 10C – Configure ESP8266 as a TCP Server

### 1. Circuit Diagram

The experiment demonstrates communication between the STM32 microcontroller and the Wemos ESP8266 Wi-Fi module using UART communication. AT commands are used to configure the ESP8266 as a Wi-Fi station and establish a TCP server.

**Hardware Components:**
- **Development Board:** STM32F401RE
- **Wi-Fi Module:** Wemos ESP8266
- **UART Peripheral:** USART6
- **Communication Interface:** UART Serial Communication
- **TCP Server Port:** 80

**Connections:**
- STM32 USART6 TX → Wemos ESP8266 RX
- STM32 USART6 RX → Wemos ESP8266 TX
- STM32 GND → Wemos GND
- Ensure that the ESP8266 is supplied with a suitable 3.3V power source.

**UART Configuration:**
- Baud Rate: 115200
- Word Length: 8 Bits
- Stop Bits: 1
- Parity: None
- Mode: Transmitter and Receiver

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates Wi-Fi configuration and TCP server initialization using an ESP8266 module connected to the STM32F401RE through USART6.

The STM32 communicates with the ESP8266 by transmitting AT commands through UART. A function named `Send_AT_Command()` sends commands to the ESP8266 and collects its responses into a response buffer.

The ESP8266 is configured through the following sequence:

1. **AT:** Checks communication between STM32 and ESP8266.
2. **AT+CWMODE=1:** Configures the ESP8266 in Wi-Fi Station mode.
3. **AT+CWJAP:** Connects the ESP8266 to the specified Wi-Fi network.
4. **AT+CIPMUX=1:** Enables multiple TCP/UDP connections.
5. **AT+CIPSERVER=1,80:** Starts a TCP server on port 80.
6. **AT+CIFSR:** Retrieves the IP address of the ESP8266.

The response received from the ESP8266 is stored in a character array. The function checks for `OK`, `ERROR`, or `FAIL` to determine the command response.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO peripherals.
4. Initialize USART6 with a baud rate of 115200.
5. Wait for 2 seconds to allow the ESP8266 module to initialize.
6. Send the `AT` command to check communication.
7. Set the ESP8266 to Wi-Fi Station mode using `AT+CWMODE=1`.
8. Connect to the Wi-Fi network using `AT+CWJAP`.
9. Enable multiple connections using `AT+CIPMUX=1`.
10. Start the TCP server on port 80 using `AT+CIPSERVER=1,80`.
11. Retrieve the ESP8266 IP address using `AT+CIFSR`.
12. Continue execution in the infinite loop.

**Code Base:**

The UART communication and AT command operations are implemented using the following STM32 HAL functions and C library functions:

- `HAL_Init()` – Initializes the HAL library.
- `HAL_UART_Init()` – Initializes the USART6 peripheral.
- `HAL_UART_Transmit()` – Sends AT commands to the ESP8266.
- `HAL_UART_Receive()` – Receives responses from the ESP8266.
- `HAL_GetTick()` – Returns the system tick count in milliseconds.
- `HAL_Delay()` – Introduces delays between AT commands.
- `memset()` – Clears the response buffer before sending a new command.
- `strlen()` – Calculates the length of the AT command.
- `strstr()` – Searches for `OK`, `ERROR`, or `FAIL` in the received response.

The `Send_AT_Command()` function handles command transmission and response reception with a maximum timeout of 15 seconds.

### 3. Inference

The STM32F401RE communicates with the Wemos ESP8266 Wi-Fi module using USART6 and AT commands.

The ESP8266 is configured in Station mode, connected to a Wi-Fi network, and initialized as a TCP server on port 80. The IP address of the module can be retrieved using the `AT+CIFSR` command.

This experiment demonstrates UART-based module communication, Wi-Fi configuration, AT command handling, and TCP server initialization using STM32 and ESP8266.
