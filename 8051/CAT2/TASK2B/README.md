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
- **GPIO Ports:** Port 1 and Port 0
- **GPIO Pins:** P1.0 and P0.0
- **Peripherals:** Two LEDs
- **Power Supply:** To be verified on hardware

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The AT89S52 development board is examined to identify the microcontroller, power supply connections, programming interface, and GPIO pins.

The GPIO pins P1.0 and P0.0 are used to control two LEDs through digital output signals.

**Pseudocode:**

1. Identify the AT89S52 microcontroller on the development board.
2. Identify the power supply and ground connections.
3. Verify the operating voltage using a digital multimeter.
4. Identify the programmer interface.
5. Identify the GPIO pins P1.0 and P0.0.
6. Identify the LEDs connected to the GPIO pins.
7. Connect the development board to the computer.
8. Open Keil µVision and select the AT89S52 microcontroller.
9. Establish communication with the development board.

**Code Base:**

Task 2A focuses on hardware identification and development environment setup.

- AT89S52 is an 8051-compatible microcontroller.
- Port P1.0 is used to control LED 1.
- Port P0.0 is used to control LED 2.
- Logic HIGH sets the GPIO output to 1.
- Logic LOW sets the GPIO output to 0.
- Keil µVision is used for Embedded C development.

### 3. Inference

The hardware bring-up procedure helps identify the AT89S52 microcontroller, its GPIO connections, and the programming interface.

The GPIO pins P1.0 and P0.0 provide the basis for controlling two LEDs in Task 2B.

---

## TASK 2B : Bare-Metal LED Blink

### 1. Circuit Diagram

The experiment demonstrates dual LED blinking using the AT89S52 microcontroller through direct GPIO control.

- **Microcontroller:** AT89S52
- **GPIO Ports:** Port 1 and Port 0
- **GPIO Pins:** P1.0 and P0.0
- **Peripheral:** Two LEDs
- **LED 1:** Connected to P1.0
- **LED 2:** Connected to P0.0
- **Power Supply:** To be verified on hardware

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

Two LEDs are controlled using pins P1.0 and P0.0 of the AT89S52 microcontroller.

The program initially sets P0.0 LOW and P1.0 HIGH. The signal at P1.0 is then repeatedly changed between HIGH and LOW states with software delays.

After the P1.0 switching sequence, P0.0 is changed between HIGH and LOW states with software delays.

The entire sequence repeats continuously using an infinite loop.

**Pseudocode:**

1. Include the 8051 register definition header file.
2. Define P1.0 as LED 1 and P0.0 as LED 2.
3. Create a delay function using two nested loops of 100 iterations each.
4. Enter an infinite loop.
5. Set P0.0 LOW and P1.0 HIGH.
6. Apply a software delay.
7. Toggle P1.0 between LOW and HIGH three times, with delays after each change.
8. Set P0.0 HIGH and apply a delay.
9. Toggle P0.0 between LOW and HIGH, ending with P0.0 LOW.
10. Repeat the sequence continuously.

**Code Base:**

- `reg51.h` provides the 8051 register definitions.
- `sbit ledpin1 = P1^0` assigns LED 1 to pin P1.0.
- `sbit ledpin2 = P0^0` assigns LED 2 to pin P0.0.
- `ledpin1 = 1` sets P1.0 HIGH.
- `ledpin1 = 0` sets P1.0 LOW.
- `ledpin2 = 1` sets P0.0 HIGH.
- `ledpin2 = 0` sets P0.0 LOW.
- `delay()` uses nested loops of 100 iterations each to introduce a software delay.
- `while(1)` continuously repeats the LED control sequence.

### 3. Inference

The program demonstrates control of two LEDs using GPIO pins P1.0 and P0.0 of the AT89S52 microcontroller.

The GPIO output states change in a programmed sequence using software delays.

The experiment demonstrates multiple GPIO output control, sequential LED switching, software delay generation, and basic bare-metal Embedded C programming using the AT89S52 microcontroller.
