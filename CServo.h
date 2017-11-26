/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSERVO_NOND_H
#define CSERVO_NOND_H

namespace pigpio_wcpp
{
    class Servo
    {
    private:
        unsigned char m_pin;
        bool          m_isAttached;

    public:
        Servo(unsigned int pin);

        bool drive(unsigned int pulseWidth);

        bool off();

        bool setFrequency(unsigned int frequencyHz);
        unsigned int frequency();

        bool setRange(PWMRange range);
        unsigned int range();

        unsigned int pulseWidth();

        bool isAttached() const;
    };
}

#endif
