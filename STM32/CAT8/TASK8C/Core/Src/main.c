
#include "main.h"
#include <stdint.h>

/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void Error_Handler(void);

int main(void)
{
    HAL_Init();

    SystemClock_Config();
    MX_GPIO_Init();

    /* Button debounce variables */
    uint8_t lastRawButtonState = GPIO_PIN_SET;
    uint8_t stableButtonState = GPIO_PIN_SET;

    uint32_t lastDebounceTime = HAL_GetTick();

    /* Press detection variables */
    uint32_t pressStartTime = 0;
    uint8_t longPressDetected = 0;

    /* Blinking mode variables */
    uint8_t blinking = 0;
    uint32_t blinkTime = 0;

    while (1)
    {
        uint32_t currentTime = HAL_GetTick();

        /* Read the button */
        uint8_t rawButtonState =
            HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);

        /*
         * Detect a change in the raw button state.
         * Restart the debounce timer whenever it changes.
         */
        if (rawButtonState != lastRawButtonState)
        {
            lastRawButtonState = rawButtonState;
            lastDebounceTime = currentTime;
        }

        /*
         * Accept the new state only if it remains stable
         * for at least 20 milliseconds.
         */
        if ((currentTime - lastDebounceTime >= 20) &&
            (rawButtonState != stableButtonState))
        {
            stableButtonState = rawButtonState;

            /* Button pressed */
            if (stableButtonState == GPIO_PIN_RESET)
            {
                pressStartTime = currentTime;
                longPressDetected = 0;
            }

            /* Button released */
            else
            {
                /*
                 * If it was not a long press,
                 * perform the short-press action.
                 */
                if (longPressDetected == 0)
                {
                    if (blinking == 1)
                    {
                        /* Stop blinking and turn LED OFF */
                        blinking = 0;
                        HAL_GPIO_WritePin(
                            GPIOC,
                            GPIO_PIN_13,
                            GPIO_PIN_SET
                        );
                    }
                    else
                    {
                        /* Toggle LED */
                        HAL_GPIO_TogglePin(
                            GPIOC,
                            GPIO_PIN_13
                        );
                    }
                }
            }
        }

        /*
         * Long-press detection.
         * No blocking delay or waiting loop is used.
         */
        if ((stableButtonState == GPIO_PIN_RESET) &&
            (longPressDetected == 0) &&
            (currentTime - pressStartTime >= 1000))
        {
            longPressDetected = 1;
            blinking = 1;
            blinkTime = currentTime;
        }

        /*
         * Non-blocking LED blinking.
         * Toggle LED every 500 milliseconds.
         */
        if ((blinking == 1) &&
            (currentTime - blinkTime >= 500))
        {
            HAL_GPIO_TogglePin(
                GPIOC,
                GPIO_PIN_13
            );

            blinkTime = currentTime;
        }
    }
}

/* System Clock Configuration */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;

    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK |
        RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 |
        RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

/* GPIO Initialization */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable GPIO clocks */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* Initially turn OFF the onboard LED (active-low) */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

    /* Configure PC13 as LED output */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* Configure PA3 as button input with internal pull-up */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* Error Handler */
void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
    /* User can add reporting code here */
}
#endif
