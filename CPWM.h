/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CPWM_NOND_H
#define CPWM_NOND_H

namespace pigpio_wcpp
{
    class PWM
    {
    private:
        unsigned char m_pin;
        bool          m_isAttached = false;

    public:
        PWM(unsigned int pin);

        bool drive(unsigned int pulseWidth);

        bool off();

        bool setFrequency(unsigned int frequencyHz);
        unsigned int frequency();

        bool setRange(PWMRange range);
        unsigned int range();
        unsigned int realRange();

        unsigned int pulseWidth();

        bool isAttached() const;
    };
}
#endif