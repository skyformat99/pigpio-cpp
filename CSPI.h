/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSPI_NOND_H
#define CSPI_NOND_H

#define SPI_STANDARD  0
#define SPI_AUXILIARY 1

#define SPI_3WIRE  1
#define SPI_4WIRE  0

#define DEFAULT_WORD_SIZE 0

namespace pigpio_wcpp
{
    enum SPIChannel
    {
        Channel1  = 0,
        Channel2  = 1,
        Auxiliary = 2
    } PACKED;

    typedef union _spi_flag_u
    {
	struct
	{
        	unsigned char mode : 2;

	        unsigned char cs0_activation : 1;
        	unsigned char cs1_activation : 1;
	        unsigned char cs2_activation : 1;

   	     	unsigned char cs0_dedicated : 1;
       	 	unsigned char cs1_dedicated : 1;
		unsigned char cs2_dedicated : 1;

	        unsigned char channel_type : 1;
        	unsigned char wire_type    : 1;

	        unsigned char transferBufferSize : 4;

	        unsigned char txSignificantBit : 1;
        	unsigned char rxSignificantBit : 1;

	        unsigned char wordSize : 6;

        	unsigned char : 8; // padding
		unsigned char : 2; // padding
	} flags;
	unsigned int value;
    } SPIFlag;


    class SPI
    {
    private:
        int          m_handler;
        bool         m_isOpen;
        unsigned int m_baudrate;
        SPIFlag      m_flag;
	unsigned int m_channel;
    public:
        SPI(SPIChannel channel, unsigned int baudrate, SPIFlag flag);
        ~SPI();

        bool open();
        bool close();

        int read(char *buffer, unsigned int length);
        int write(char *buffer, unsigned int length);

        int transfer(char *receive, char *send, unsigned int length);

        SPIFlag flag() const;
        unsigned int baudrate() const;
        bool isOpen() const;
    };
}

#endif
