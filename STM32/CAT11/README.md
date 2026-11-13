# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION 10C

**DATE:** 12/10/2026

**NAME OF EXP:** HTTP Server – STM32–Wemos Wi-Fi Modem Using AT Commands

**HARDWARE SETUP / PLATFORM:** STM32 Development Board + Wemos D1 Mini (ESP8266) + STM32CubeMX + Keil MDK + Node-RED

---

## TASK 10C : Configure ESP8266 as a TCP Server

### 1. Circuit Diagram

The STM32 development board communicates with the Wemos D1 Mini (ESP8266) through UART. The ESP8266 is configured as a TCP server on port 80.

**Connections:**

- STM32 TX → ESP8266 RX
- STM32 RX → ESP8266 TX
- STM32 GND → ESP8266 GND
- Appropriate power supply to both boards

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The STM32 sends AT commands to the ESP8266 through UART to configure the Wi-Fi module as a TCP server.

The `AT` command verifies modem communication. `AT+CIPMUX=1` enables multiple connections, while `AT+CIPSERVER=1,80` starts a TCP server on port 80.

**Pseudocode:**

1. Initialize STM32 HAL and UART.
2. Establish UART communication with ESP8266.
3. Send `AT` to check modem communication.
4. Send `AT+CIPMUX=1` to enable multiple connections.
5. Send `AT+CIPSERVER=1,80` to start the server.
6. Check the ESP8266 responses.
7. Wait for incoming client connections.

**Code Base:**

```text
AT
AT+CIPMUX=1
AT+CIPSERVER=1,80
```

### 3. Inference

The experiment demonstrates how STM32 can configure an ESP8266 module as a TCP server using UART AT commands, allowing the system to accept incoming network connections.

---

## TASK 10D : Observe HTTP Request and Construct a Static HTTP Response

### 1. Circuit Diagram

A browser sends an HTTP GET request to the ESP8266 server. The ESP8266 forwards the request to STM32 through UART using an `+IPD` notification.

The STM32 constructs an HTTP response and sends it back to the browser through the ESP8266.

**Communication Flow:**

```text
Browser
   |
   | HTTP GET Request
   v
ESP8266
   |
   | +IPD Notification
   v
STM32
   |
   | HTTP Response
   v
ESP8266
   |
   | TCP Connection
   v
Browser
```

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

When the browser sends an HTTP request, the ESP8266 forwards the request to STM32 through UART.

STM32 identifies the incoming request and constructs an HTTP response containing a status line, HTTP headers, a blank line, and an HTML body.

The response is transmitted using `AT+CIPSEND`, after the ESP8266 provides the `>` prompt.

**Pseudocode:**

1. Initialize UART communication.
2. Configure ESP8266 as a TCP server.
3. Wait for an HTTP request from the browser.
4. Receive the `+IPD` notification.
5. Identify the connection ID.
6. Construct the HTTP response.
7. Calculate the response length.
8. Send `AT+CIPSEND` with the connection ID and response length.
9. Wait for the `>` prompt.
10. Transmit the HTTP response.
11. Display the HTML page in the browser.

**Code Base:**

Example HTTP request:

```text
+IPD,0,XXX:GET / HTTP/1.1
Host: 192.168.1.105
```

CIPSEND command:

```c
sprintf(cmd, "AT+CIPSEND=%d,%d\r\n",
        link_id, data_length);
```

HTTP response:

```c
sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "\r\n"
        "<html><body><h1>STM32 IoT Node</h1></body></html>",
        body_length);
```

### 3. Inference

The experiment demonstrates how an STM32 microcontroller can receive HTTP requests through an ESP8266 module, construct an HTML response, and transmit it to a web browser.

---

## TASK 10E : Node-RED as a Second HTTP Client of STM32/ESP8266 HTTP Server

### 1. Circuit Diagram

Node-RED acts as an HTTP client that communicates with the STM32/ESP8266 HTTP server through a Wi-Fi network.

**Node-RED Flow:**

```text
[Inject] → [HTTP Request] → [Debug]
```

**Communication Flow:**

```text
Node-RED
   |
   | HTTP Request
   v
ESP8266
   |
   | UART
   v
STM32
   |
   | HTTP Response
   v
ESP8266
   |
   v
Node-RED Debug Panel
```

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The STM32 and ESP8266 together operate as an HTTP server.

Node-RED uses an Inject node to trigger an HTTP request. The HTTP Request node sends the request to the ESP8266 server IP address, and the Debug node displays the response returned by the STM32 server.

**Pseudocode:**

1. Configure the STM32/ESP8266 HTTP server.
2. Open the Node-RED editor.
3. Add an Inject node.
4. Add an HTTP Request node.
5. Add a Debug node.
6. Connect the nodes in sequence.
7. Enter the ESP8266 IP address in the HTTP Request node.
8. Deploy the flow.
9. Trigger the Inject node.
10. Observe the received response in the Debug panel.

**Code Base:**

Node-RED flow:

```text
Inject → HTTP Request → Debug
```

HTTP Request URL:

```text
http://<ESP8266_IP>/
```

Example HTML response:

```html
<html>
  <body>
    <h1>STM32 IoT Node</h1>
  </body>
</html>
```

### 3. Inference

The experiment demonstrates how Node-RED can function as a second HTTP client for an STM32/ESP8266 HTTP server.

The Node-RED Debug node provides a way to view the HTTP response generated by the STM32-based system.
