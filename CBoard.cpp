/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

using namespace pigpio_wcpp;

bool Board::m_isInitialised = false;

Board::Board()
{
	
}

Board::~Board()
{
	if(m_isInitialised == false)
		return;
	gpioTerminate();
}

bool Board::initialise()
{
	if(m_isInitialised) return true;

	int ret_;
	ret_ = gpioInitialise();
	m_isInitialised = !(ret_<0);
	return (m_isInitialised);
}

void Board::kill()
{
	if(!m_isInitialised) return;
	gpioTerminate();
}

bool Board::isInitialised() const
{
	return (m_isInitialised);
}

unsigned int Board::version()
{
	return (gpioVersion());
}

int hardwareRevision()
{
	return gpioHardwareRevision();
}

void Board::delayInSeconds(double seconds)
{
	time_sleep(seconds);
}

void Board::delayInMicro(double microseconds)
{
	gpioDelay(microseconds);
}

int Board::ticks()
{
	return gpioTick();
}

int Board::shell(char *script, char *arguments)
{
	return shell(script, arguments);
}

int Board::GetPadDriveStrength(Pad pad)
{
	return (gpioGetPad((int)pad));
}

bool Board::SetPadDriveStrength(Pad pad, int driveStrength_mA)
{
	return (gpioSetPad((int)pad, driveStrength_mA) == 0);
}

bool Board::SetDMAMemoryAllocationMode(DMAMemoryAllocationMode mode)
{
	if(m_isInitialised) return false;
	return (gpioCfgMemAlloc((int)mode) == 0);
}

bool Board::SetDMAChannel(DMAChannel channel)
{
	if(m_isInitialised) return false;
	return (gpioCfgDMAchannel((int)channel) == 0);
}

bool Board::SetDMAChannel(DMAChannel primaryChannel, DMAChannel secondaryChannel)
{
	if(m_isInitialised) return false;
	return (gpioCfgDMAchannels((int)primaryChannel, (int)secondaryChannel) == 0);
}

unsigned int Board::GetGPIOPort(GPIOPort port)
{
	if(port == Port1)
		return (unsigned int)gpioRead_Bits_0_31();
	return (unsigned int)gpioRead_Bits_32_53();
}

bool Board::SetGPIOPort(GPIOPort port, unsigned int bitmap)
{
	if(port == Port1)
		return (gpioWrite_Bits_0_31_Set(bitmap) == 0);
	return (gpioWrite_Bits_32_53_Set(bitmap) == 0);
}

bool Board::ResetGPIOPort(GPIOPort port)
{
	if(port == Port1)
		return (gpioWrite_Bits_0_31_Clear(0xFFFFFFFF) == 0);
	return (gpioWrite_Bits_32_53_Clear(0xFFFFFFFF) == 0);
}
