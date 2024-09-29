#include "CLOCK_recon.h"




/*仍需改进*/
void CLOCK::clock_init(GPIO_TypeDef*x)
{
    if (x==GPIOA)
        __HAL_RCC_GPIOA_CLK_ENABLE();
    if (x==GPIOB)
        __HAL_RCC_GPIOB_CLK_ENABLE();
    if (x==GPIOC)
        __HAL_RCC_GPIOC_CLK_ENABLE();
    if (x==GPIOD)
        __HAL_RCC_GPIOD_CLK_ENABLE();
    if (x==GPIOE)
        __HAL_RCC_GPIOE_CLK_ENABLE();
    if (x==GPIOF)
        __HAL_RCC_GPIOF_CLK_ENABLE();
    if (x==GPIOG)
        __HAL_RCC_GPIOG_CLK_ENABLE();
    if (x==GPIOH)
        __HAL_RCC_GPIOH_CLK_ENABLE();
    if (x==GPIOI)
        __HAL_RCC_GPIOI_CLK_ENABLE();
    // switch((int)x)
    // {
    //     case GPIOA:
    //         __HAL_RCC_GPIOA_CLK_ENABLE();
    //         break;
    //     case GPIOB:
    //         __HAL_RCC_GPIOB_CLK_ENABLE();
    //         break;
    //     case GPIOC:
    //         __HAL_RCC_GPIOC_CLK_ENABLE();
    //         break;
    //     case GPIOD:
    //         __HAL_RCC_GPIOD_CLK_ENABLE();
    //         break;
    //     case GPIOE:
    //         __HAL_RCC_GPIOE_CLK_ENABLE();
    //         break;
    //     case GPIOF:
    //         __HAL_RCC_GPIOF_CLK_ENABLE();
    //         break;
    //     case GPIOG:
    //         __HAL_RCC_GPIOG_CLK_ENABLE();
    //         break;
    //     case GPIOH:
    //         __HAL_RCC_GPIOH_CLK_ENABLE();
    //         break;
    //     case GPIOI:
    //         __HAL_RCC_GPIOI_CLK_ENABLE();
    //         break;
    //     default:
    //         break;
    // }
}


void CLOCK::Delay_us(uint16_t us)
{
    uint32_t reload_value=us*(SystemCoreClock/1000000);
    SysTick->LOAD=reload_value;
    SysTick->VAL=0;
    SysTick->CTRL=SysTick_CTRL_ENABLE_Msk;
    while((SysTick->CTRL&SysTick_CTRL_COUNTFLAG_Msk)==0);
    SysTick->CTRL=0;
}