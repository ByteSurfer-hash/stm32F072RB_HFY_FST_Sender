#include <stdint.h>

#define LED_PIN 5U
#define RADIO_DATA_PIN 8U
#define RCC_AHBENR (*(volatile uint32_t *)0x40021014UL)
#define GPIOA_MODER (*(volatile uint32_t *)0x48000000UL)
#define GPIOA_ODR (*(volatile uint32_t *)0x48000014UL)
#define GPIOB_MODER (*(volatile uint32_t *)0x48000400UL)
#define GPIOB_ODR (*(volatile uint32_t *)0x48000414UL)
#define RCC_AHBENR_GPIOAEN (1UL << 17)
#define RCC_AHBENR_GPIOBEN (1UL << 18)

static void delay(volatile uint32_t count)
{
    while (count > 0U)
    {
        count--;
    }
}

int main(void)
{
    RCC_AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;

    GPIOA_MODER &= ~(3UL << (LED_PIN * 2U));
    GPIOA_MODER |= (1UL << (LED_PIN * 2U));

    GPIOB_MODER &= ~(3UL << (RADIO_DATA_PIN * 2U));
    GPIOB_MODER |= (1UL << (RADIO_DATA_PIN * 2U));
    GPIOB_ODR &= ~(1UL << RADIO_DATA_PIN);

    while (1)
    {
        GPIOA_ODR ^= (1UL << LED_PIN);
        delay(800000U);
    }
}