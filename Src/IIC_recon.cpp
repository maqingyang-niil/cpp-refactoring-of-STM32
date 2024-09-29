#include "IIC_recon.h"

IIC::IIC(GPIO_TypeDef*sda_port,uint32_t sda_pin,GPIO_TypeDef*scl_port,uint32_t scl_pin,uint8_t deviceAddr):
GPIO(sda_port,sda_pin,GPIO_MODE_OUTPUT_OD,GPIO_PULLUP,GPIO_SPEED_FAST),
SDA(sda_port,sda_pin,GPIO_MODE_OUTPUT_OD,GPIO_PULLUP,GPIO_SPEED_FAST),
SCL(scl_port,scl_pin,GPIO_MODE_OUTPUT_OD,GPIO_PULLUP,GPIO_SPEED_FAST),DeviceAddr(deviceAddr){
    
}
IIC::~IIC()
{
    
}

void IIC::IIC_SDA(uint8_t n)
{
    if (n!=0)
    SDA.SET();
    if (n==0)
    SDA.RESET();
    Delay_us(20);
}

void IIC::IIC_SCL(uint8_t n)
{
    if (n!=0)
    SCL.SET();
    if (n==0)
    SCL.RESET();
    Delay_us(20);
}

void IIC::IIC_Start()
{
    IIC_SDA(1);
    IIC_SCL(1);
    IIC_SDA(0);
    IIC_SCL(0);
}

void IIC::IIC_Stop()
{
    IIC_SDA(0);
    IIC_SCL(1);
    IIC_SDA(1);
}

void IIC::SendByte(uint8_t mes)
{
    for (uint8_t i=0;i<8;++i)
    {
        IIC_SDA(mes&(0x80>>i));
        IIC_SCL(1);
        IIC_SCL(0);
    }
}

uint8_t IIC::ReceiveByte()
{
    uint8_t byte=0x00;
    IIC_SDA(1);
    for (uint8_t i=0;i<8;++i)
    {
        IIC_SCL(1);
        if (SDA.StatusRead())
            byte|=(0x80>>i);
        IIC_SCL(0);
    }
    return byte;
}

void IIC::Bus_Release()
{
    IIC_SCL(1);
    IIC_SDA(1);
}

void IIC::SendAck(uint8_t ack)
{
    IIC_SDA(ack);
    IIC_SCL(1);
    IIC_SCL(0);
}

uint8_t IIC::RecevieAck()
{
    uint8_t ack=0x00;
    IIC_SDA(1);
    IIC_SCL(1);
    ack=SDA.StatusRead();
    IIC_SCL(0);
    return ack;
}

void IIC::Write_Single_Byte(uint8_t addr,uint8_t data)
{
    IIC_Start();
    SendByte(DeviceAddr);
    RecevieAck();
    SendByte(addr);
    RecevieAck();
    SendByte(data);
    RecevieAck();
    IIC_Stop();
}

void IIC::Write_Multi_Byte(uint8_t addr,uint8_t*data,uint8_t size)
{
    IIC_Start();
    SendByte(DeviceAddr);
    RecevieAck();
    SendByte(addr);
    RecevieAck();
    for (uint16_t i=0;i<size;++i)
    {
        SendByte(*data);
        RecevieAck();
        ++data;
    }
}

uint8_t*IIC::Read_Multi_Byte(uint8_t addr,uint8_t*data,uint8_t size)
{
    IIC_Start();
    SendByte(DeviceAddr);
    RecevieAck();
    SendByte(addr);
    RecevieAck();
    IIC_Start();
    SendByte(DeviceAddr|0x01);
    RecevieAck();
    for (uint8_t i=0;i<size;++i)
    {
        (*data)=ReceiveByte();
        SendAck(0);
        ++data;
    }
    SendAck(1);
    IIC_Stop();
    return data;
}

void IIC::Set_DeviceAddress(uint8_t addr)
{
    DeviceAddr=addr;
}

