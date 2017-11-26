/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CThread.h"

using namespace pigpio_wcpp;

Thread::Thread()
{
    m_thread   = NULL;
}

Thread::~Thread()
{
    if(m_thread == NULL)
        return;
    gpioStopThread(m_thread);
    free(m_thread);
}

bool Thread::run(ThreadCallback callback, void *userData)
{
    m_thread = gpioStartThread(callback, userData);

    return (m_thread != NULL);
}

void Thread::kill()
{
    if(m_thread == NULL)
        return;
    gpioStopThread(m_thread);
    free(m_thread);
}
