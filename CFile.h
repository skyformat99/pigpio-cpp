/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CFILE_NOND_H
#define CFILE_NOND_H

#define FILE_MODE(_x, _y)  (_x|_y)

namespace pigpio_wcpp
{
    enum FileMode
    {
        Read         = PI_FILE_READ,
        Write        = PI_FILE_WRITE,
        ReadAndWrite = PI_FILE_RW,
        Append       = PI_FILE_APPEND,
        Create       = PI_FILE_CREATE,
        Truncated    = PI_FILE_TRUNC
    } PACKED;

    enum FileSeekFrom
    {
        SeekFromStart   = PI_FROM_START,
        SeekFromEnd     = PI_FROM_END,
        SeekFromCurrent = PI_FROM_CURRENT
    } PACKED;

    class File
    {
    private:
        int      m_fileHandler;
        bool     m_isOpen;
        char    *m_fileName;

    public:
        File(const char *fileName);
        ~File();

        static int ListFiles(char *pattern, char *buffer, int bufferSize);

        bool open(int fileMode);
        bool close();

        int write(char *payload);
        int write(char *payload, int length);

        int read(char *buffer, int bufferSize);

        int seek(FileSeekFrom seekFrom, int offset);

        bool isOpen() const;
    };
}

#endif
