#ifndef __GPIO_RECON_H
#define __GPIO_RECON_H

#include "stm32f4xx_hal.h"
#include "CLOCK_recon.h"
class GPIO:public CLOCK
{
public:
    GPIO(GPIO_TypeDef*port,uint32_t pin,
                uint32_t mode=GPIO_MODE_OUTPUT_PP,
                uint32_t pull=GPIO_NOPULL,
                uint32_t speed=GPIO_SPEED_FAST,
                uint32_t alternate=0);
    ~GPIO();
    void RESET();
    void SET();
    uint8_t StatusRead();
private:
    void init();
    GPIO_TypeDef*Port;
    uint32_t Pin;       
    uint32_t Mode;      
    uint32_t Pull;      
    uint32_t Speed;    
    uint32_t Alternate;  
    

};



















#endif //__GPIO_RECON_H