/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSERIAL_NOND_H
#define CSERIAL_NOND_H

namespace pigpio_wcpp
{
    enum SerialBaudRate
    {
        SerialBaudRate50     = 50,
        SerialBaudRate75     = 75,
        SerialBaudRate100    = 110,
        SerialBaudRate134    = 134,
        SerialBaudRate150    = 150,
        SerialBaudRate200    = 200,
        SerialBaudRate300    = 300,
        SerialBaudRate600    = 600,
        SerialBaudRate1200   = 1200,
        SerialBaudRate1800   = 1800,
        SerialBaudRate2400   = 2400,
        SerialBaudRate4800   = 4800,
        SerialBaudRate9600   = 9600,
        SerialBaudRate19200  = 19200,
        SerialBaudRate38400  = 38400,
        SerialBaudRate57600  = 57600,
        SerialBaudRate115200 = 115200,
        SerialBaudRate230400 = 230400
    };

    class Serial
    {
    private:
        int               m_handler;
        char             *m_serialPortName;
        SerialBaudRate    m_baudRate;
        bool              m_isOpen;

    public:
        Serial(char *serialPortName, SerialBaudRate baudRate);
        ~Serial();

        SerialBaudRate baudRate() const;
        bool isOpen() const;

        bool open();
        bool close();

        bool write(unsigned char byte);
        bool write(char *buffer, unsigned int length);

        int  readByte();
        bool readBuffer(char *buffer, unsigned int capacity);

        int hasData();
    };
}

#endif
