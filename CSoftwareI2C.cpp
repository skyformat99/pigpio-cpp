/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CSoftwareI2C.h"

using namespace pigpio_wcpp;

SoftwareI2C::SoftwareI2C(SoftwareI2CPins pins, int baudrate)
{
    m_isOpen = false;
    m_baudrate = baudrate;
    m_pins = pins;
}

SoftwareI2C::~SoftwareI2C()
{
    close();
}

bool SoftwareI2C::open()
{
    m_isOpen = (bbI2COpen(m_pins.sda, m_pins.scl, m_baudrate)) == 0;
    return m_isOpen;
}

bool SoftwareI2C::close()
{
    if(!m_isOpen) return false;
    m_isOpen = !(bbI2CClose(m_pins.sda) == 0);
    return !m_isOpen;
}

int SoftwareI2C::transfer(char *sendBuffer, int sendBufferLength,
                          char *receiveBuffer, int receiveBufferLength)
{
    return bbI2CZip(m_pins.sda, 
                    sendBuffer, sendBufferLength,
                    receiveBuffer, receiveBufferLength);
}

SoftwareI2CPins SoftwareI2C::pins() const
{
    return m_pins;
}

int SoftwareI2C::baudrate() const
{
    return m_baudrate;
}

SoftwareI2CPins SoftwareI2C::SetPins(unsigned char sda, unsigned char scl)
{
    SoftwareI2CPins pins_;
    pins_.sda = sda;
    pins_.scl = scl;
    return pins_;
}
