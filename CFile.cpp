/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CFile.h"

using namespace pigpio_wcpp;

File::File(const char *fileName)
{
    int len_ = strlen(fileName);
    m_fileName = new char[len_ + 1];
    m_fileName[len_] = 0;
    m_fileHandler = -1;
    m_isOpen = false;
}

File::~File()
{
    close();
    free(m_fileName);
}

int File::ListFiles(char *pattern, char *buffer, int bufferSize)
{
    return fileList(pattern, buffer, bufferSize);
}

bool File::open(int fileMode)
{
    m_fileHandler = fileOpen(m_fileName, fileMode);
    m_isOpen = (m_fileHandler)>0;
    return m_isOpen;
}

bool File::close()
{
    if(!m_isOpen) return false;
    m_isOpen = !(fileClose(m_fileHandler)>-1);
    return m_isOpen;
}

int File::write(char *payload)
{
    int len_ = strlen(payload);
    return fileWrite(m_fileHandler, payload, len_);
}

int File::write(char *payload, int length)
{
    return fileWrite(m_fileHandler, payload, length);
}

int File::read(char *buffer, int bufferSize)
{
    return fileRead(m_fileHandler, buffer, bufferSize);
}

int File::seek(FileSeekFrom seekFrom, int offset)
{
    return fileSeek(m_fileHandler, offset, (int)seekFrom);
}

bool File::isOpen() const
{
    return m_isOpen;
}
