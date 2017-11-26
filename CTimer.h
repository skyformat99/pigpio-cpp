/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CTIMER_NOND_H
#define CTIMER_NOND_H

#define TimerCallback          gpioTimerFuncEx_t

namespace pigpio_wcpp
{
	enum TimerID
	{
		Timer1  = 0,
		Timer2  = 1,
		Timer3  = 2,
		Timer4  = 3,
		Timer5  = 4,
		Timer6  = 5,
		Timer7  = 6,
		Timer8  = 7,
		Timer9  = 8,
		Timer10 = 9
    } PACKED;
    
    class Timer
    {
    private:
        TimerID        m_timerId;
        bool           m_isCreated;
        TimerCallback  m_callback;

    public:
        Timer(TimerID timerId, TimerCallback callback);
        ~Timer();
        
        bool start(unsigned int milliSeconds, void *userData);
        bool stop();

        TimerID id() const;
        bool    isCreated() const;
    };
}
#endif
