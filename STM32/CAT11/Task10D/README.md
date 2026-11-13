# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 11

**NAME OF EXP:** STM32–ESP8266 TCP Server with HTTP Webpage Response

**HARDWARE SETUP / PLATFORM:** STM32CubeMX + Keil MDK + STM32F401RE Development Board + Wemos ESP8266 Wi-Fi Module

---

## TASK 10D – Observe the HTTP Request

### 1. Circuit Diagram

The experiment demonstrates communication between the STM32 microcontroller and the Wemos ESP8266 Wi-Fi module using UART communication. The ESP8266 acts as a Wi-Fi interface and TCP server, while the STM32 processes incoming HTTP requests and generates webpage responses.

**Hardware Components:**

- **Development Board:** STM32F401RE
- **Wi-Fi Module:** Wemos ESP8266
- **UART Peripheral:** USART6
- **Communication Interface:** UART Serial Communication
- **TCP Server Port:** 80
- **Output:** Dynamic HTML Webpage

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

The experiment demonstrates the implementation of a basic HTTP web server using the STM32F401RE and Wemos ESP8266 Wi-Fi module.

The STM32 communicates with the ESP8266 through USART6 using AT commands. Initially, the ESP8266 is configured in Wi-Fi Station mode and connected to the specified Wi-Fi network. Multiple connections are enabled, and a TCP server is started on port 80.

When a client accesses the ESP8266 server through a web browser, the ESP8266 sends the incoming request to the STM32 through UART using the `+IPD` notification.

The STM32 extracts the connection ID from the received request and generates a random uppercase letter between A and Z. It then creates a dynamic HTML webpage containing the heading "STM32 IoT Node", the message "Hello from STM32", and the generated random letter.

The HTTP response is transmitted to the ESP8266 using the `AT+CIPSEND` command. After sending the webpage, the TCP connection is closed using `AT+CIPCLOSE`.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO peripherals.
4. Initialize USART6 with a baud rate of 115200.
5. Wait for 2 seconds to allow the ESP8266 to initialize.
6. Send the `AT` command to check communication.
7. Configure the ESP8266 in Wi-Fi Station mode using `AT+CWMODE=1`.
8. Connect to the Wi-Fi network using `AT+CWJAP`.
9. Retrieve the ESP8266 IP address using `AT+CIFSR`.
10. Enable multiple connections using `AT+CIPMUX=1`.
11. Start the TCP server on port 80 using `AT+CIPSERVER=1,80`.
12. Continuously wait for incoming HTTP requests from clients.
13. Receive the request and identify the connection ID from the `+IPD` notification.
14. Generate a random uppercase letter between A and Z.
15. Create an HTML webpage containing the STM32 IoT Node heading and random letter.
16. Construct an HTTP response with the appropriate headers and webpage content.
17. Send the `AT+CIPSEND` command with the connection ID and response length.
18. Wait for the ESP8266 data transmission prompt (`>`).
19. Transmit the HTTP response through UART.
20. Close the client connection using `AT+CIPCLOSE`.
21. Repeat the process continuously.

**Code Base:**

The UART communication, TCP server operations, HTTP response generation, and string handling are implemented using the following STM32 HAL functions and C library functions:

- `HAL_Init()` – Initializes the HAL library.
- `HAL_UART_Init()` – Initializes the USART6 peripheral.
- `HAL_UART_Transmit()` – Transmits AT commands and HTTP responses to the ESP8266.
- `HAL_UART_Receive()` – Receives data and requests from the ESP8266.
- `HAL_GetTick()` – Returns the system tick count in milliseconds.
- `HAL_Delay()` – Introduces time delays.
- `sendAT()` – Sends AT commands and checks the ESP8266 response.
- `waitForPrompt()` – Waits for the `>` prompt before sending HTTP response data.
- `receiveRequest()` – Receives incoming client requests and stores them in a request buffer.
- `memset()` – Clears the receive buffers.
- `strlen()` – Calculates string lengths.
- `strstr()` – Searches for specific response strings such as `OK`, `ERROR`, `FAIL`, and `+IPD`.
- `sscanf()` – Extracts the TCP connection ID from the incoming request.
- `snprintf()` – Generates AT commands, HTML content, and HTTP response headers.
- `rand()` – Generates a random number used to select an uppercase letter.

The HTTP response contains the following headers:

- `HTTP/1.1 200 OK`
- `Content-Type: text/html`
- `Content-Length`
- `Connection: close`

### 3. Inference

The STM32F401RE successfully communicates with the Wemos ESP8266 through USART6 and processes incoming HTTP client requests.

When a client accesses the TCP server through a web browser, the STM32 generates a dynamic HTML webpage displaying the message "Hello from STM32" along with a randomly generated uppercase letter.

This experiment demonstrates UART communication, TCP server implementation, HTTP request handling, dynamic webpage generation, and Wi-Fi-based communication using STM32 and ESP8266.
