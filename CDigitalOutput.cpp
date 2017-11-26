/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */
#include "CDigitalOutput.h"

using namespace pigpio_wcpp;

DigitalOutput::DigitalOutput(unsigned char pin)
{
	int ret_;
	m_pin = pin;

	ret_ = gpioSetMode(m_pin, PI_OUTPUT);
	m_pinAssigned = (ret_ == 0);
}

bool DigitalOutput::high()
{
	return (gpioWrite(m_pin, 1) == 0);
}

bool DigitalOutput::low()
{
	return (gpioWrite(m_pin, 0) == 0);
}

unsigned char DigitalOutput::pin() const
{
	return (m_pin);
}

bool DigitalOutput::isPinAssigned() const
{
	return (m_pinAssigned);
}

int DigitalOutput::pinState()
{
	return (gpioRead(m_pin));
}

bool DigitalOutput::triggerPulse(unsigned int pulseWidth, PinState state)
{
    return (gpioTrigger(m_pin, pulseWidth, (unsigned int)state)==0);
}
