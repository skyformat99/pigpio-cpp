/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSOFTWAREREADINGSERIAL_NOND_H
#define CSOFTWAREREADINGSERIAL_NOND_H

#define SRS_MAX_BAUDRATE 250000
#define SRS_MIN_BAUDRATE 50

namespace pigpio_wcpp
{
    class SoftwareReadingSerial
    {
    private:
        int  m_pin;
        int  m_dataBits;
        int  m_serialLogicLevel;
        int  m_baudrate;
        bool m_isOpen;

    public:
        SoftwareReadingSerial(int pin, int dataBits, int baudrate);
        SoftwareReadingSerial(int pin, int dataBits, int baudrate, LogicLevel logicLevel);
        ~SoftwareReadingSerial();

        int read(char *buffer, int bufferSize);

        bool open();
        bool close();

        bool        setLogicLeve(LogicLevel logicLevel);
        LogicLevel  serialLogicLevel() const;

        int dataBits() const;

        bool isOpen() const;
    };
}

#endif
