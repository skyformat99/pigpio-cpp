/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CSoftwareReadingSerial.h"

using namespace pigpio_wcpp;

SoftwareReadingSerial::SoftwareReadingSerial(int pin, int dataBits, int baudrate)
{
    m_pin      = pin;
    m_serialLogicLevel = High;
    m_isOpen   = false;
    m_dataBits = dataBits;
    m_baudrate = baudrate;
}

SoftwareReadingSerial::SoftwareReadingSerial(int pin, int dataBits, int baudrate, LogicLevel logicLevel)
{
    m_pin      = pin;
    m_serialLogicLevel = logicLevel;
    m_isOpen   = false;
    m_dataBits = dataBits;
    m_baudrate = baudrate;
}

SoftwareReadingSerial::~SoftwareReadingSerial()
{
    if(m_isOpen)
        close();
}

int SoftwareReadingSerial::read(char *buffer, int bufferSize)
{
    return gpioSerialRead(m_pin, buffer, bufferSize);
}

bool SoftwareReadingSerial::open()
{
    if(m_isOpen) return false;

    m_isOpen = gpioSerialReadOpen(m_pin, m_baudrate, m_dataBits) == 0;
    return m_isOpen;
}

bool SoftwareReadingSerial::close()
{
    if(!m_isOpen) return false;
    m_isOpen =  !(gpioSerialReadClose(m_pin) == 0);
    return !m_isOpen;
}

bool SoftwareReadingSerial::setLogicLeve(LogicLevel logicLevel)
{
    if(m_isOpen) return false;

    m_serialLogicLevel = logicLevel;
    return (gpioSerialReadInvert(m_pin, (int)logicLevel) == 0);
}
LogicLevel SoftwareReadingSerial::serialLogicLevel() const
{
    return (LogicLevel) m_serialLogicLevel;
}

bool SoftwareReadingSerial::isOpen() const
{
    return m_isOpen;
}

int SoftwareReadingSerial::dataBits() const
{
    return m_dataBits;
}
