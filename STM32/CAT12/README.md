# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION 11

**DATE:** 14/10/2026

**NAME OF EXP:** STM32F401RE Cortex-M4: GPIO and User Input Programming

**HARDWARE SETUP / PLATFORM:** STM32 NUCLEO-F401RE Development Board + STM32CubeMX + Keil MDK + STM32 HAL Libraries

---

## TASK 1 : On-board LED Bring-Up

### 1. Circuit Diagram

The on-board LED of the STM32 NUCLEO-F401RE board is used to verify GPIO output configuration.

The user LED (LD2) is connected to PA5 on the NUCLEO-F401RE board.

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The STM32 microcontroller controls the on-board LED through a GPIO output pin.

The GPIO pin is configured as an output using STM32CubeMX. The LED is toggled at a fixed time interval using HAL functions to verify the board's GPIO operation.

**Pseudocode:**

1. Initialize the STM32 HAL library.
2. Configure the system clock.
3. Enable the GPIO peripheral clock.
4. Configure PA5 as a GPIO output.
5. Enter an infinite loop.
6. Toggle the on-board LED.
7. Introduce a fixed delay.
8. Repeat continuously.

**Code Base:**

```c
while (1)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    HAL_Delay(500);
}
```

### 3. Inference

The task demonstrates the use of GPIO output configuration to control the on-board LED of the STM32 NUCLEO-F401RE board.

Blinking the LED at a fixed interval provides a basic method for verifying GPIO functionality and microcontroller programming.

---

## TASK 2 : On-board Switch Control with State Remembrance

### 1. Circuit Diagram

The on-board user push button is used as a GPIO input to control the on-board LED.

The NUCLEO-F401RE board uses:

- **PA5:** On-board user LED (LD2)
- **PC13:** On-board user button (B1)

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The on-board push button controls the LED using GPIO input detection.

Whenever a valid button press is detected, the LED changes its state from ON to OFF or OFF to ON.

The previous LED state is remembered after the button is released, so the LED does not return automatically to its initial state.

**Pseudocode:**

1. Initialize the HAL library and system clock.
2. Configure PA5 as GPIO output.
3. Configure PC13 as GPIO input.
4. Initialize a variable to store the LED state.
5. Continuously monitor the push button.
6. Detect a new button press.
7. Apply a short debounce delay.
8. Toggle the stored LED state.
9. Update the LED output.
10. Wait for the button to be released before detecting another press.

**Code Base:**

```c
uint8_t led_state = 0;

while (1)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
        == GPIO_PIN_SET)
    {
        HAL_Delay(20);

        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
            == GPIO_PIN_SET)
        {
            led_state = !led_state;

            HAL_GPIO_WritePin(
                GPIOA,
                GPIO_PIN_5,
                led_state ? GPIO_PIN_SET : GPIO_PIN_RESET
            );

            while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
                   == GPIO_PIN_SET)
            {
            }
        }
    }
}
```

### 3. Inference

The task demonstrates GPIO input handling and LED state control using the STM32 microcontroller.

The LED retains its previous state after the push button is released, demonstrating state remembrance and button press detection.

---

## TASK 3 : Short-Press and Long-Press Detection

### 1. Circuit Diagram

The on-board push button is used to detect different press durations, and the on-board LED is used to indicate the corresponding action.

The NUCLEO-F401RE board uses:

- **PA5:** On-board user LED (LD2)
- **PC13:** On-board user button (B1)

![Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The STM32 microcontroller monitors the duration for which the on-board push button is pressed.

The time of the button press is measured using `HAL_GetTick()`.

When the button is released, the measured duration is compared against a predefined threshold.

Different actions are performed depending on whether the press is classified as short or long.

For the example implementation below:

- **Short press:** Toggle the LED.
- **Long press:** Turn the LED OFF.
- **Threshold:** 1000 milliseconds.

These actions and the threshold are example design choices; the evaluation sheet does not prescribe specific values.

**Pseudocode:**

1. Initialize the HAL library and system clock.
2. Configure PA5 as GPIO output.
3. Configure PC13 as GPIO input.
4. Monitor the button state.
5. Record the time when the button is pressed.
6. Wait until the button is released.
7. Calculate the duration of the button press.
8. Compare the duration against the threshold.
9. If the duration is less than the threshold, toggle the LED.
10. Otherwise, turn the LED OFF.
11. Repeat continuously.

**Code Base:**

```c
uint32_t press_start;
uint32_t press_duration;

while (1)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
        == GPIO_PIN_SET)
    {
        HAL_Delay(20);

        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
            == GPIO_PIN_SET)
        {
            press_start = HAL_GetTick();

            while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
                   == GPIO_PIN_SET)
            {
            }

            press_duration = HAL_GetTick() - press_start;

            if (press_duration < 1000)
            {
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
            }
            else
            {
                HAL_GPIO_WritePin(
                    GPIOA,
                    GPIO_PIN_5,
                    GPIO_PIN_RESET
                );
            }
        }
    }
}
```

### 3. Inference

The task demonstrates how the STM32 microcontroller can distinguish between short and long button presses using time-based input detection.

Measuring the button press duration allows a single push button to perform different actions, improving the flexibility of user input handling.
