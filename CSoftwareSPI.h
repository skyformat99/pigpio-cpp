/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSOFTWARESPI_NOND_H
#define CSOFTWARESPI_NOND_H

namespace pigpio_wcpp
{
    typedef union _software_SoftwareSPI_flag
    {
	struct
	{
	        unsigned char mode : 2;
	        unsigned char chipSelectionActivation : 1;
	        unsigned char : 8;
		unsigned char : 3;
	        unsigned char txSignificantBit : 1;
	        unsigned char rxSignificantBit : 1;
	        unsigned char : 8;
		unsigned char : 8;
	} flags;
	unsigned int value;
    } SoftwareSoftwareSPIFlag;

    typedef struct _software_SoftwareSPI_pins
    {
        unsigned char mosi;
        unsigned char miso;
        unsigned char sclk;
        unsigned char cs;
    } SoftwareSoftwareSPIPins;

    class SoftwareSPI
    {
    private:
        SoftwareSoftwareSPIPins       m_pins;
        SoftwareSoftwareSPIFlag       m_flag;
        bool          m_isOpen;
        unsigned int  m_baudrate;

    public:
        static SoftwareSoftwareSPIPins ConfigurePins(unsigned char mosi,
                                     unsigned char miso,
                                     unsigned char sclk,
                                     unsigned char cs);

        static SoftwareSoftwareSPIFlag ConfigureFlag(unsigned char mode,
                                     unsigned char chipSelectionActivation,
                                     unsigned char txSignificantBit,
                                     unsigned char rxSignificantBit);

        SoftwareSPI(SoftwareSoftwareSPIPins pins,
                    SoftwareSoftwareSPIFlag flag,
                    unsigned int baudrate);

        ~SoftwareSPI();

        bool open();
        bool close();

        int transfer(char *receive, char *send, unsigned int length);

        SoftwareSoftwareSPIFlag flag() const;
        SoftwareSoftwareSPIPins pins() const;
    };
}

#endif
