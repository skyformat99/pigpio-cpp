/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CDIGITALOUTOUT_NOND_H
#define CDIGITALOUTPUT_NOND_H

namespace pigpio_wcpp
{
	class DigitalOutput
	{
	private:
		bool           m_pinAssigned;
		unsigned char  m_pin;

	public:
		DigitalOutput(unsigned char pin);

		bool high();
		bool low();

		int pinState();

		bool triggerPulse(unsigned int pulseWidth, PinState state); 

		unsigned char pin() const;
		bool isPinAssigned() const;
	};
}
#endif

