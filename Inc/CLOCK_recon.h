#ifndef __CLOCK_RECON_H
#define __CLOCK_RECON_H

#include "stm32f4xx_hal.h"

class CLOCK
{
protected:
    void Delay_us(uint16_t);
    void clock_init(GPIO_TypeDef*);
    
};






#endif /*__CLOCK_RECON_H*/