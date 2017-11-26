/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CSPI.h"

using namespace pigpio_wcpp;

SPI::SPI(SPIChannel channel, unsigned int baudrate, SPIFlag flag)
{
    m_handler  = -1;
    m_isOpen   = false;
    m_baudrate = baudrate;
    m_channel  = (unsigned int) (*(&channel));
    m_flag     = flag;
}

SPI::~SPI()
{
    close();
}

bool SPI::open()
{
    unsigned int flag_ = m_flag.value;
	//(unsigned int)(*((void *) &m_flag));
    m_handler = spiOpen(m_channel, m_baudrate, flag_);
    m_isOpen = m_handler > -1;
    return m_isOpen;
}

bool SPI::close()
{
    if(!m_isOpen) return false;
    return (spiClose(m_handler) == 0);
}

int SPI::read(char *buffer, unsigned int length)
{
    if(!m_isOpen) return -1;
    return spiRead(m_handler, buffer, length);
}

int SPI::write(char *buffer, unsigned int length)
{
    if(!m_isOpen) return -1;
    return spiWrite(m_handler, buffer, length);
}

int SPI::transfer(char *receive, char *send, unsigned int length)
{
    if(!m_isOpen) return -1;
    return spiXfer(m_handler, send, receive, length);
}

SPIFlag SPI::flag() const
{
    return m_flag;
}

unsigned int SPI::baudrate() const
{
    return m_baudrate;
}

bool SPI::isOpen() const
{
    return m_isOpen;
}
