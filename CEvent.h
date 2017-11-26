/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */
 
#include "CBoard.h"

#ifndef CEVENT_NOND_H
#define CEVENT_NOND_H

#define EventCallback      eventFuncEx_t

namespace pigpio_wcpp
{
    enum EventID
    {
        Event1   = 0,
        Event2   = 1,
        Event3   = 2,
        Event4   = 3,
        Event5   = 4,
        Event6   = 5,
        Event7   = 6,
        Event8   = 7,
        Event9   = 8,
        Event10  = 9,
        Event11  = 10,
        Event12  = 11,
        Event13  = 12,
        Event14  = 13,
        Event15  = 14,
        Event16  = 15,
        Event17  = 16,
        Event18  = 17,
        Event19  = 18,
        Event20  = 19,
        Event21  = 20,
        Event22  = 21,
        Event23  = 22,
        Event24  = 23,
        Event25  = 24,
        Event26  = 25,
        Event27  = 26,
        Event28  = 27,
        Event29  = 28,
        Event30  = 29,
        Event31  = 30,
        Event32  = 31,
    } PACKED;

    class Event
    {
    private:
        EventID        m_eventID;
        bool           m_isCreated;
        EventCallback  m_callback;

    public:
        Event(EventID eventID, EventCallback callback);
        ~Event();

        bool connect(void *userData);
        bool trigger();
    };

}
#endif

