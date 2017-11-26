/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CServo.h"

using namespace pigpio_wcpp;

Servo::Servo(unsigned int pin)
{
	m_isAttached = false;
	m_pin = pin;
}

bool Servo::drive(unsigned int pulseWidth)
{
    m_isAttached = gpioServo(m_pin, pulseWidth) == 0;
    return m_isAttached; 
}

bool Servo::off()
{
    if(!m_isAttached) return false;
    return gpioServo(m_pin, 0) == 0;
}

bool Servo::setFrequency(unsigned int frequencyHz)
{
    return (gpioSetPWMfrequency(m_pin, frequencyHz) > 4);
}

unsigned int Servo::frequency()
{
    return gpioGetPWMfrequency(m_pin);
}

bool Servo::setRange(PWMRange range)
{
    return gpioSetPWMrange(m_pin, (unsigned int)range) > 24;
}
unsigned int Servo::range()
{
    return gpioGetPWMrange(m_pin);
}

unsigned int Servo::pulseWidth()
{
    return gpioGetServoPulsewidth(m_pin);
}

bool Servo::isAttached() const
{
    return m_isAttached;
}
