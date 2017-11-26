/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CI2C_NOND_H
#define CI2C_NOND_H

#define I2CMessage pi_i2c_msg_t

namespace pigpio_wcpp
{
    enum I2CBus
    {
        Bus0,
        Bus1
    } PACKED;

    typedef struct _bit
    {
         unsigned char state : 1;
         unsigned char       : 7;
    } Bit;

    class I2C
    {
    private:
        I2CBus  m_bus;
        int     m_handler;
        bool    m_isOpen;

        unsigned char m_address;

    public:
        I2C(I2CBus bus, unsigned char address);
        ~I2C();

        I2CBus bus() const;
        unsigned char address() const;
        bool isOpen() const;

        bool open();
        bool close();

        bool write(Bit bit);
        bool write(unsigned char byte);
        bool write(unsigned char registerAddress, unsigned char registerValue);
        bool write(unsigned char registerAddress, unsigned int registerWord);
        bool write(unsigned char registerAddress, char *buffer, unsigned int length);
        bool write(char *buffer, unsigned int bufferSize);
        bool write(I2CMessage *messages, unsigned int count);

        int read();
        int read(unsigned char registerAddress, bool wordSize);
        int read(unsigned char registerAddress, char *buffer, unsigned int count);
        int read(unsigned char registerAddress, char *buffer);
        int read(char *buffer, unsigned int bufferSize);

        int processCall(unsigned char registerAddress, unsigned int wordValue);
        int processCall(unsigned char registerAddress, char *buffer, unsigned int count);

        int transaction(char *sendBuffer, unsigned int sendBufferLength,
                        char *receiveBuffer, unsigned int receiveBufferLength);

        static Bit SetBit(unsigned char state);
    };
}

#endif
