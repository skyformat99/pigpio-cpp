/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CTimer.h"

using namespace pigpio_wcpp;

Timer::Timer(TimerID timerId, TimerCallback callback)
{
    m_timerId   = timerId;
    m_isCreated = false;
    m_callback  = callback;
}

Timer::~Timer()
{
    if (!m_isCreated)
        return;
    stop();
}

bool Timer::start(unsigned int milliSeconds, void *userData)
{
    m_isCreated = gpioSetTimerFuncEx((unsigned int)m_timerId, milliSeconds, m_callback, userData)==0;
    return m_isCreated;
}

bool Timer::stop()
{
    if(!m_isCreated) return false;
    m_isCreated = !(gpioSetTimerFuncEx((unsigned int)m_timerId, 0, NULL, NULL) == 0);
    return m_isCreated;
}

TimerID Timer::id() const
{
    return m_timerId;
}

bool Timer::isCreated() const
{
    return m_isCreated;
}
