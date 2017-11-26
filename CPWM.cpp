/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CPWM.h"

using namespace pigpio_wcpp;

PWM::PWM(unsigned int pin)
{
    m_pin = pin;
}

bool PWM::drive(unsigned int pulseWidth)
{
    m_isAttached = gpioPWM(m_pin, pulseWidth) == 0;
    return m_isAttached; 
}

bool PWM::off()
{
    if(!m_isAttached) return false;
    return gpioServo(m_pin, 0) == 0;
}

bool PWM::setFrequency(unsigned int frequencyHz)
{
    return (gpioSetPWMfrequency(m_pin, frequencyHz) > 4);
}

unsigned int PWM::frequency()
{
    return gpioGetPWMfrequency(m_pin);
}

bool PWM::setRange(PWMRange range)
{
    return gpioSetPWMrange(m_pin, (unsigned int)range) > 24;
}
unsigned int PWM::range()
{
    return gpioGetPWMrange(m_pin);
}

unsigned int PWM::realRange()
{
    return gpioGetPWMrealRange(m_pin);
}

unsigned int PWM::pulseWidth()
{
    return gpioGetServoPulsewidth(m_pin);
}

bool PWM::isAttached() const
{
    return m_isAttached;
}
