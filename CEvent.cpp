/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CEvent.h"

using namespace pigpio_wcpp;

Event::Event(EventID eventID, EventCallback callback)
{
    m_eventID = eventID;
    m_callback = callback;
    m_isCreated = false;
}

Event::~Event()
{
    if(m_isCreated) 
    {
        eventSetFuncEx(m_eventID, NULL, NULL);
    }
}

bool Event::connect(void *userData)
{
    m_isCreated = ((eventSetFuncEx(m_eventID, m_callback, userData)) == 0);
    return m_isCreated;
}

bool Event::trigger()
{
    if(!m_isCreated) return false;
    return (eventTrigger(m_eventID) == 0);
}
