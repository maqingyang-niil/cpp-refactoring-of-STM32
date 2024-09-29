#include "GPIO_recon.h"



GPIO::GPIO(GPIO_TypeDef*port,uint32_t pin,
            uint32_t mode,
            uint32_t pull,
            uint32_t speed,
            uint32_t alternate):Port(port),Mode(mode),Pull(pull),Speed(speed),Alternate(alternate){
                    init();
            }

GPIO::~GPIO()
{

}

void GPIO::init()
{
    clock_init(Port);
    GPIO_InitTypeDef init_structure;
    init_structure.Pin=Pin;
    init_structure.Mode=Mode;
    init_structure.Pull=Pull;
    init_structure.Speed=Speed;
    init_structure.Alternate=Alternate;
    HAL_GPIO_Init(Port,&init_structure);
}

void GPIO::RESET()
{
    HAL_GPIO_WritePin(Port,Pin,GPIO_PIN_RESET);
}

void GPIO::SET()
{
    HAL_GPIO_WritePin(Port,Pin,GPIO_PIN_SET);
}

uint8_t GPIO::StatusRead()
{
    return HAL_GPIO_ReadPin(Port,Pin);
}