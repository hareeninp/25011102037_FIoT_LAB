# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 9

**NAME OF EXP:** String Based Application Logic

**HARDWARE SETUP / PLATFORM:** STM32CubeMX + Keil MDK + STM32 Development Board Blue Pill STM32F103C8T6

---

## TASK 9B – UART Command Interface for LED Control

### 1. Circuit Diagram

The experiment uses the onboard LED of the STM32 Blue Pill development board and USART1 for serial communication.

**Hardware Components:**
- **Development Board:** STM32 Blue Pill
- **Microcontroller IC:** STM32F103C8T6
- **GPIO Pin:** PC13
- **UART Peripheral:** USART1
- **TX Pin:** PA9 (USART1_TX)
- **RX Pin:** PA10 (USART1_RX)
- **Peripheral:** Onboard LED
- **Communication Interface:** USB-to-TTL Serial Converter

**Connections:**
- STM32 PA9 (TX) → USB-to-TTL RX
- STM32 PA10 (RX) → USB-to-TTL TX
- STM32 GND → USB-to-TTL GND

**UART Configuration:**
- Baud Rate: 9600
- Word Length: 8 Bits
- Stop Bits: 1
- Parity: None
- Mode: Transmitter and Receiver

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates LED control using UART serial commands and the STM32 HAL library.

USART1 is configured for serial communication at a baud rate of 9600. The microcontroller receives commands from the Serial Monitor, stores the received characters in a command buffer, and checks the entered command when the user presses Enter.

Three commands are supported:

- **LED ON:** Turns ON the onboard LED by setting PC13 to GPIO_PIN_RESET.
- **LED OFF:** Turns OFF the onboard LED by setting PC13 to GPIO_PIN_SET.
- **LED TOGGLE:** Continuously toggles the onboard LED at intervals of 500 milliseconds.

The program also displays the entered characters (echo), provides responses for valid commands, and displays an error message for invalid commands.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Configure GPIO pin PC13 as output.
4. Initialize USART1 with a baud rate of 9600.
5. Set the onboard LED to its initial OFF state.
6. Display the UART Command Interface message on the Serial Monitor.
7. Continuously check for incoming UART characters.
8. Store received characters in a command buffer and display them back (echo).
9. When Enter is pressed, compare the received command:
   - If the command is "LED ON", turn ON the LED.
   - If the command is "LED OFF", turn OFF the LED.
   - If the command is "LED TOGGLE", enable continuous LED toggling.
   - Otherwise, display "Invalid command".
10. In toggle mode, toggle the LED every 500 milliseconds.
11. Display the command prompt again.
12. Repeat the process continuously.

**Code Base:**

The UART communication and GPIO operations are performed using the following STM32 HAL functions and C library functions:

- `HAL_Init()` – Initializes the HAL library.
- `HAL_UART_Init()` – Initializes the USART1 peripheral.
- `HAL_UART_Receive()` – Receives characters through UART.
- `HAL_UART_Transmit()` – Transmits messages and echoes received characters.
- `HAL_GPIO_WritePin()` – Sets or resets the GPIO output pin.
- `HAL_GPIO_TogglePin()` – Toggles the LED state.
- `HAL_GetTick()` – Returns the system tick count in milliseconds.
- `HAL_Delay()` – Introduces a delay.
- `strcmp()` – Compares the entered command with predefined strings.
- `strlen()` – Calculates the length of a string.

The `toggle_mode` variable controls whether continuous LED toggling is enabled. The `last_toggle` variable stores the previous toggle time to generate a 500 ms interval without blocking UART communication.

### 3. Inference

The STM32 Blue Pill successfully receives and processes UART commands to control the onboard LED.

The LED can be switched ON, switched OFF, or made to blink continuously using the commands entered through the Serial Monitor. This experiment demonstrates UART-based command processing, GPIO output control, string comparison, and non-blocking time-based LED toggling using the STM32 HAL library.
