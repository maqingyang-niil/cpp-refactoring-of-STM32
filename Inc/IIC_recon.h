#ifndef __IIC_RECON_H
#define __IIC_RECON_H

#include "stm32f4xx_hal.h"
#include "GPIO_recon.h"

class IIC:public GPIO
{
public:
    explicit IIC(GPIO_TypeDef*,uint32_t,GPIO_TypeDef*,uint32_t,uint8_t);
    ~IIC();
    void SendByte(uint8_t);
    uint8_t ReceiveByte();
    void Write_Single_Byte(uint8_t,uint8_t);
    void Write_Multi_Byte(uint8_t,uint8_t*,uint8_t);
    uint8_t Read_Single_Byte(uint8_t);
    uint8_t*Read_Multi_Byte(uint8_t,uint8_t*,uint8_t);

    void Set_DeviceAddress(uint8_t);
private:
    void Bus_Release();
    void SendAck(uint8_t);
    uint8_t RecevieAck();
    void IIC_SDA(uint8_t);
    void IIC_SCL(uint8_t);
    void IIC_Start();
    void IIC_Stop();
    
    uint8_t DeviceAddr;
    GPIO SDA;
    GPIO SCL;
};
























#endif/*__IIC_RECON_H*/