/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include  "CSerial.h"

using namespace pigpio_wcpp;

Serial::Serial(char *serialPortName, SerialBaudRate baudRate)
{
    m_serialPortName = new char[strlen(serialPortName)+1];
    strcpy(m_serialPortName, serialPortName);
    m_serialPortName[strlen(serialPortName)] = 0;
    m_baudRate = baudRate;
    m_isOpen = false;
    m_handler = -1;
}

Serial::~Serial()
{
    if(!m_isOpen)
        return;
    serClose(m_handler);
    free(m_serialPortName);
}

SerialBaudRate Serial::baudRate() const
{
    return m_baudRate;
}

bool Serial::isOpen() const
{
    return m_isOpen;
}

bool Serial::open()
{
    if(m_isOpen) return false;

    m_handler = serOpen(m_serialPortName, (unsigned int)m_baudRate, 0);
	m_isOpen = (m_handler > -1);
    return m_isOpen;
}

bool Serial::close()
{
    if(!m_isOpen) return false;

    return (serClose(m_handler) == 0);
}

bool Serial::write(unsigned char byte)
{
    if(!m_isOpen) return -1;

    return (serWriteByte(m_handler, byte) == 0);
}

bool Serial::write(char *buffer, unsigned int length)
{
    if(!m_isOpen) return false;

    return (serWrite(m_handler, buffer, length) == 0);
}

int Serial::readByte()
{
    if(!m_isOpen) return -1;

    return serReadByte(m_handler);
}

bool Serial::readBuffer(char *buffer, unsigned int capacity)
{
    if(!m_isOpen) return false;

    return (serRead(m_handler, buffer, capacity) == 0);
}

int Serial::hasData()
{
    if(!m_isOpen) return -1;

    return serDataAvailable(m_handler);
}
