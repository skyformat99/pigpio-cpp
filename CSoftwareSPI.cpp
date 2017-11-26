/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CSoftwareSPI.h"

using namespace pigpio_wcpp;

SoftwareSoftwareSPIPins SoftwareSPI::ConfigurePins(unsigned char mosi,
                      				  unsigned char miso,
		                                  unsigned char sclk,
                       				  unsigned char cs)
{
    SoftwareSoftwareSPIPins spi_pins;

    spi_pins.mosi = mosi;
    spi_pins.miso = miso;
    spi_pins.sclk = sclk;
    spi_pins.cs   = cs;

    return (spi_pins);
}

SoftwareSoftwareSPIFlag SoftwareSPI::ConfigureFlag(unsigned char mode,
                       				  unsigned char chipSelectionActivation,
		                                  unsigned char txSignificantBit,
                       				  unsigned char rxSignificantBit)
{
    SoftwareSoftwareSPIFlag flag;

    flag.flags.mode = mode & 0x3;
    flag.flags.chipSelectionActivation = chipSelectionActivation & 0x1;
    flag.flags.txSignificantBit        = txSignificantBit & 0x1;
    flag.flags.rxSignificantBit        = rxSignificantBit & 0x1;

    return (flag);
}

SoftwareSPI::SoftwareSPI(SoftwareSoftwareSPIPins pins, SoftwareSoftwareSPIFlag flag, unsigned int baudrate)
{
    m_pins  = pins;
    m_flag  = flag;
    m_baudrate = baudrate;
    m_isOpen   = false;
}

SoftwareSPI::~SoftwareSPI()
{
    close();
}

bool SoftwareSPI::open()
{
    int flag_;
    flag_ = m_flag.value & 0xffff; // ((int)m_flag) & 0xffff;
    m_isOpen = (bbSPIOpen(m_pins.cs, m_pins.miso, m_pins.mosi, m_pins.sclk, m_baudrate, flag_) == 0);

    return m_isOpen;
}

bool SoftwareSPI::close()
{
    if(!m_isOpen) return true;

    return (bbSPIClose(m_pins.cs) == 0);
}

int SoftwareSPI::transfer(char *receive, char *send, unsigned int length)
{
    return bbSPIXfer(m_pins.cs, send, receive, length);
}

SoftwareSoftwareSPIFlag SoftwareSPI::flag() const
{
    return m_flag;
}

SoftwareSoftwareSPIPins SoftwareSPI::pins() const
{
    return m_pins;
}
