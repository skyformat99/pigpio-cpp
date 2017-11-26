/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CDigitalInput.h"

using namespace pigpio_wcpp;

DigitalInputPin::DigitalInputPin(int pin)
{
    int ret_;

    m_hasEvent = false;
    m_pin = pin;
    ret_ = gpioSetMode(pin, PI_INPUT);
    m_isAssigned = (ret_ == 0);
    setPullResistor(PullDown);

    setNoiseFilter(-1, -1);
    setGlitchFilter(-1);
}

DigitalInputPin::~DigitalInputPin()
{
    if(m_hasEvent)
        eventSetFuncEx(m_pin, NULL, NULL);
}

bool DigitalInputPin::setPullResistor(PullResistor pullResistor)
{
    return (gpioSetPullUpDown(m_pin, (unsigned int)pullResistor) == 0);
}

int DigitalInputPin::pinState() const
{
    return (PinState)gpioRead(m_pin);
}

unsigned char DigitalInputPin::pin() const
{
    return m_pin;
}

bool DigitalInputPin::isAssigned() const
{
    return m_isAssigned;
}

bool DigitalInputPin::hasEvent() const
{
    return m_hasEvent;
}

// call <event> whenever GPIO <m_pin> changes state
bool DigitalInputPin::signal(Edge edge, IOCallbackExtended event, void *userData)
{
    if(m_hasEvent || m_hasInterrupt) return false;    
    m_hasEvent = (gpioSetAlertFuncEx(m_pin, event, userData) == 0);
    return m_hasEvent;
}

//  or approximately every <timeout> milliseconds
bool DigitalInputPin::watchdog(unsigned int timeout)
{
    if(!m_hasEvent) return false;
    if(!m_hasInterrupt) return false;
    return (gpioSetWatchdog(m_pin, timeout) == 0);
}

bool DigitalInputPin::interrupt(Edge edge, ISRCallback callback, int timeout, void *userData)
{
    if(m_hasEvent || m_hasInterrupt) return false;
    m_hasInterrupt = (gpioSetISRFuncEx(m_pin, (int)edge, timeout, callback, userData) == 0);
    return m_hasInterrupt;
}

void DigitalInputPin::removeSignal()
{
    if(!m_hasEvent) return;
    gpioSetAlertFuncEx(m_pin, NULL, NULL);
    m_hasEvent = false;
}

void DigitalInputPin::removeInterrupt()
{
    if(!m_hasInterrupt) return;
    gpioSetISRFuncEx(m_pin, 2, 0, NULL, NULL);
    m_hasInterrupt = false;
}

NoiseFilter   DigitalInputPin::noiseFilter() const
{
    return m_noiseFilter;
}

GlitchFilter  DigitalInputPin::glitchFilter() const
{
    return m_glitchFilter;
}

void DigitalInputPin::setNoiseFilter(int steady, int active)
{
    m_noiseFilter.steady = steady;
    m_noiseFilter.active = active;
    gpioNoiseFilter(m_pin, m_noiseFilter.steady, m_noiseFilter.active);
}

void DigitalInputPin::setGlitchFilter(int steady)
{
    m_glitchFilter.steady = steady;
    gpioGlitchFilter(m_pin, m_glitchFilter.steady);
}
