# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 2

**DATE:** 20/07/2026

**NAME OF EXP:** 8051 Development Board Tool Chain Setup – AT89S52

**HARDWARE SETUP / PLATFORM:** AT89S52 Microcontroller Development Board + Keil µVision

---

## TASK 2A : Hardware Board Bring-Up

### 1. Circuit Diagram

The experiment involves identifying and verifying the hardware components of the AT89S52 microcontroller development board.

- **Microcontroller:** AT89S52
- **CPU Core:** 8051
- **GPIO Port:** Port 1
- **GPIO Pin:** P1.0
- **Peripheral:** LED
- **LED Configuration:** Active LOW
- **Power Supply:** To be verified on hardware

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The AT89S52 development board is examined to identify the microcontroller, power supply connections, programming interface, and GPIO pins.

The LED is connected to Port P1.0 and operates using active-low logic.

**Pseudocode:**

1. Identify the AT89S52 microcontroller on the development board.
2. Identify the power supply and ground connections.
3. Verify the operating voltage using a digital multimeter.
4. Identify the programmer interface.
5. Identify the LED connected to Port P1.0.
6. Verify the active-low LED configuration.
7. Connect the development board to the computer.
8. Open Keil µVision and select the AT89S52 microcontroller.
9. Establish communication with the development board.

**Code Base:**

Task 2A focuses on hardware identification and development environment setup.

- AT89S52 is an 8051-compatible microcontroller.
- Port P1.0 is used for LED control in the supplied program.
- Logic LOW turns the LED ON.
- Logic HIGH turns the LED OFF.
- Keil µVision is used for Embedded C development.

### 3. Inference

The hardware bring-up procedure helps identify the AT89S52 microcontroller, its GPIO connections, and the programming interface.

The LED connected to P1.0 uses active-low logic, providing the basis for direct GPIO control in Task 2B.

---

## TASK 2B : Bare-Metal LED Blink

### 1. Circuit Diagram

The experiment demonstrates LED blinking using the AT89S52 microcontroller through direct GPIO register access.

- **Microcontroller:** AT89S52
- **GPIO Port:** Port 1
- **GPIO Pin:** P1.0
- **Peripheral:** LED with current-limiting resistor
- **LED Configuration:** Active LOW
- **Power Supply:** To be verified on hardware

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The LED is connected to pin P1.0 of the AT89S52 microcontroller.

The microcontroller continuously switches the pin between LOW and HIGH states, creating a blinking effect.

Since the LED is active-low, setting P1.0 to LOW turns the LED ON, while setting it to HIGH turns the LED OFF.

A custom software delay function introduces time intervals between LED transitions.

**Pseudocode:**

1. Include the 8051 register definition header file.
2. Define P1.0 as the LED control pin.
3. Create a delay function using nested loops.
4. Turn the LED ON by setting P1.0 LOW.
5. Call the delay function.
6. Turn the LED OFF by setting P1.0 HIGH.
7. Call the delay function again.
8. Repeat continuously.

**Code Base:**

- `reg52.h` provides the 8051 register definitions.
- `sbit LED = P1^0` assigns the LED to pin P1.0.
- `LED = 0` sets the pin LOW and turns the LED ON.
- `LED = 1` sets the pin HIGH and turns the LED OFF.
- `delay()` uses nested loops of 500 and 120 iterations to generate a software delay.
- `while(1)` continuously repeats the LED blinking operation.

### 3. Inference

The LED connected to P1.0 is programmed to blink continuously as the microcontroller alternates between LOW and HIGH output states.

The experiment demonstrates GPIO output control, active-low LED operation, software delay generation, and basic bare-metal Embedded C programming using the AT89S52 microcontroller.

The blinking frequency depends on the microcontroller clock frequency and software delay execution time.
