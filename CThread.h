/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CTHREAD_NOND_H
#define CTHREAD_NOND_H

#define ThreadCallback      gpioThreadFunc_t

namespace pigpio_wcpp
{
	class Thread
	{
	private:
		pthread_t       *m_thread;
		ThreadCallback   m_callback;

	public:
		Thread();
		~Thread();

		bool run(ThreadCallback callback, void *userData);
		void kill();
	};
}
#endif

