#include "CI2C.h"

using namespace pigpio_wcpp;

I2C::I2C(I2CBus bus, unsigned char address)
{
    m_bus     = bus;
    m_address = address;
    m_handler = -1;
    m_isOpen  = false;
}

I2C::~I2C()
{
    close();
}

I2CBus I2C::bus() const
{
    return m_bus;
}

unsigned char I2C::address() const
{
    return m_address;
}

bool I2C::isOpen() const
{
    return m_isOpen;
}

bool I2C::open()
{
    m_handler = i2cOpen((unsigned int)m_bus, m_address, 0);
    m_isOpen = (m_handler > -1);
    return m_isOpen;
}

bool I2C::close()
{
    if(!m_isOpen) return false;
    m_isOpen = !(i2cClose(m_handler) > -1);
    return !m_isOpen;
}

bool I2C::write(Bit bit)
{
    if(!m_isOpen) return false;
    return (i2cWriteQuick(m_handler, bit.state) == 0);
}

bool I2C::write(unsigned char byte)
{
    if(!m_isOpen) return false;
    return (i2cWriteByte(m_handler, byte) == 0);
}

bool I2C::write(unsigned char registerAddress, unsigned char registerValue)
{
    if(!m_isOpen) return false;
    return (i2cWriteByteData(m_handler, registerAddress, registerValue) == 0);
}

bool I2C::write(unsigned char registerAddress, unsigned int registerWord)
{
    if(!m_isOpen) return false;
    return (i2cWriteWordData(m_handler, registerAddress, registerWord) == 0);
}

bool I2C::write(unsigned char registerAddress, char *buffer, unsigned int length)
{
    if(!m_isOpen) return false;
    return (i2cWriteI2CBlockData(m_handler, registerAddress, buffer, length) == 0);
}

bool I2C::write(char *buffer, unsigned int bufferSize)
{
    if(!m_isOpen) return false;
    return (i2cWriteDevice(m_handler, buffer, bufferSize) == 0);
}

bool I2C::write(I2CMessage *messages, unsigned int count)
{
    if(!m_isOpen) return false;
    return (i2cSegments(m_handler, messages, count) == 0);
}

int I2C::read()
{
    if(!m_isOpen) return -1;
    return i2cReadByte(m_handler);
}

int I2C::read(unsigned char registerAddress, bool wordSize)
{
    if(!m_isOpen) return -1;
    if(wordSize)
    {
        return i2cReadWordData(m_handler, registerAddress);
    }
    return i2cReadByteData(m_handler, registerAddress);
}

int I2C::read(unsigned char registerAddress, char *buffer)
{
    if(!m_isOpen) return -1;
    return i2cReadBlockData(m_handler, registerAddress, buffer);
}

int I2C::read(unsigned char registerAddress, char *buffer, unsigned int count)
{
    if(!m_isOpen) return -1;
    return i2cReadI2CBlockData(m_handler, registerAddress, buffer, count);
}

int I2C::read(char *buffer, unsigned int bufferSize)
{
    if(!m_isOpen) return -1;
    return i2cReadDevice(m_handler, buffer, bufferSize);
}

int I2C::processCall(unsigned char registerAddress, unsigned int wordValue)
{
    if(!m_isOpen) return -1;
    return i2cProcessCall(m_handler, registerAddress, wordValue);
}

int I2C::processCall(unsigned char registerAddress, char *buffer, unsigned int count)
{
    if(!m_isOpen) return -1;
    return i2cBlockProcessCall(m_handler, registerAddress, buffer, count);
}

int I2C::transaction(char *sendBuffer, unsigned int sendBufferLength,
                char *receiveBuffer, unsigned int receiveBufferLength)
{
    if(!m_isOpen) return -1;
    return i2cZip(m_handler, sendBuffer, sendBufferLength, receiveBuffer, receiveBufferLength);
}

Bit I2C::SetBit(unsigned char state)
{
    Bit bit_;
    bit_.state = state & 0x1;
    return bit_;
}
