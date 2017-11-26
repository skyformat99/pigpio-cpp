/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSOFTWAREI2C_NOND_H
#define CSOFTWAREI2C_NOND_H

#define SOFTWARE_I2C_MAX_BAUDRATE 500000
#define SOFTWARE_I2C_MIN_BAUDRATE 50

namespace pigpio_wcpp
{
    typedef struct _sofware_i2c_pins
    {
        unsigned char sda;
        unsigned char scl;
    } SoftwareI2CPins;

    class SoftwareI2C
    {
    private:
        SoftwareI2CPins m_pins;
        int             m_baudrate;
        bool            m_isOpen;

    public:
        SoftwareI2C(SoftwareI2CPins pins, int baudrate);
        ~SoftwareI2C();

        bool open();
        bool close();

        int transfer(char *sendBuffer, int sendBufferLength,
                     char *receiveBuffer, int receiveBufferLength);

        SoftwareI2CPins pins() const;
        int baudrate() const;

        static SoftwareI2CPins SetPins(unsigned char sda, unsigned char scl);
    };
}

#endif
