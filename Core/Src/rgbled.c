#include "main.h"
#include <stdbool.h>
#include "bootloader.h"

#if   defined(USE_PA2_LEDPB3PB4) || defined(USE_PA2_LEDPB4PB3)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3 | LL_GPIO_PIN_4)
#elif defined(USE_PA2_LEDPB3)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3)
#elif defined(USE_PA2_LEDPB4)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_4)
#elif defined(USE_PA2_LEDPB3PB4PA15) || defined(USE_PA2_LEDPB4PB3PA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_15)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3 | LL_GPIO_PIN_4)
#elif defined(USE_PA2_LEDPB3PA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_15)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3)
#elif defined(USE_PA2_LEDPB4PA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_15)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_4)
#elif defined(USE_PA2_LEDPA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_15)
#elif defined(USE_PB4_LEDPB3PA2) || defined(USE_PB4_LEDPA2PB3)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_2)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3)
#elif defined(USE_PB4_LEDPB3)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3)
#elif defined(USE_PB4_LEDPA2)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_2)
#elif defined(USE_PB4_LEDPB3PA2PA15) || defined(USE_PB4_LEDPA2PB3PA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_2 | LL_GPIO_PIN_15)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3)
#elif defined(USE_PB4_LEDPB3PA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_15)
#define LEDS_PIN_MASK_B    (LL_GPIO_PIN_3)
#elif defined(USE_PB4_LEDPA2PA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_2 | LL_GPIO_PIN_15)
#elif defined(USE_PB4_LEDPA15)
#define LEDS_PIN_MASK_A    (LL_GPIO_PIN_15)
#endif

#if defined(LEDS_PIN_MASK_A) || defined(LEDS_PIN_MASK_B)

void led_init()
{
    //LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    //LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    // already enabled in MX_GPIO_INPUT_INIT

    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;

    #if defined(LEDS_PIN_MASK_A)
    GPIO_InitStruct.Pin  = LEDS_PIN_MASK_A;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    LL_GPIO_ResetOutputPin(GPIOA, LEDS_PIN_MASK_A);
    #endif
    #if defined(LEDS_PIN_MASK_B)
    GPIO_InitStruct.Pin  = LEDS_PIN_MASK_B;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    LL_GPIO_ResetOutputPin(GPIOB, LEDS_PIN_MASK_B);
    #endif
}

void led_off()
{
    #if defined(LEDS_PIN_MASK_A)
    LL_GPIO_SetPinMode(GPIOA, LEDS_PIN_MASK_A, LL_GPIO_MODE_INPUT);
    #endif
    #if defined(LEDS_PIN_MASK_B)
    LL_GPIO_SetPinMode(GPIOB, LEDS_PIN_MASK_B, LL_GPIO_MODE_INPUT);
    #endif
}

#endif
