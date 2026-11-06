#include "stm32f0xx.h"

#define LED_PIN 5U
#define RADIO_DATA_PIN 8U

static void delay(volatile uint32_t count)
{
    while (count > 0U)
    {
        count--;
    }
}

int main(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;

    GPIOA->MODER &= ~(3UL << (LED_PIN * 2U));
    GPIOA->MODER |= (1UL << (LED_PIN * 2U));

    GPIOB->MODER &= ~(3UL << (RADIO_DATA_PIN * 2U));
    GPIOB->MODER |= (1UL << (RADIO_DATA_PIN * 2U));
    GPIOB->ODR &= ~(1UL << RADIO_DATA_PIN);

    while (1)
    {
        GPIOA->ODR ^= (1UL << LED_PIN);
        delay(800000U);
    }
}