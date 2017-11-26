/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CDIGITALINPUTPIN_NOND_H
#define CDIGITALINPUTPIN_NOND_H

namespace pigpio_wcpp
{
	typedef struct _noise_filter
	{
		int steady;
		int active;
	} NoiseFilter;

	typedef struct _glitch_filter
	{
		int steady;
	} GlitchFilter;

	enum PullResistor
	{
		Clear    = PI_PUD_OFF,
		PullUp   = PI_PUD_UP,
		PullDown = PI_PUD_DOWN
    } PACKED;

    enum Edge
	{
		OnRisingEdge  = 1,
		OnFallingEdge = 0,
		OnEitherEdge  = 2
	} PACKED;

	class DigitalInputPin
	{
	private:
		unsigned char  m_pin;
		bool           m_isAssigned;
		bool           m_hasEvent;
		bool           m_hasInterrupt;
		NoiseFilter    m_noiseFilter;
		GlitchFilter   m_glitchFilter;

	public:
		DigitalInputPin(int pin);
		~DigitalInputPin();
		
		bool setPullResistor(PullResistor pullResistor);
		
		int pinState() const;
		unsigned char pin() const;
		bool isAssigned() const;

		bool hasEvent()   const;
		bool hasInterrupt() const;

		void removeSignal();
		void removeInterrupt();

        bool watchdog(unsigned int timeout);
		bool signal(Edge edge, IOCallbackExtended event, void *userData);
		bool interrupt(Edge edge, ISRCallback callback, int timeout, void *userData);

		NoiseFilter   noiseFilter() const;
		GlitchFilter  glitchFilter() const;

		void setNoiseFilter(int steady, int active);
		void setGlitchFilter(int steady);
	};
}
#endif
