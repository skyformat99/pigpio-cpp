/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CBoard.h"

#ifndef CSCRIPT_NOND_H
#define CSCRIPT_NOND_H

namespace pigpio_wcpp
{
    enum ScriptStatus
    {
        Initing = PI_SCRIPT_INITING,
        Halted  = PI_SCRIPT_HALTED,
        Running = PI_SCRIPT_RUNNING,
        Waiting = PI_SCRIPT_WAITING,
        Failed  = PI_SCRIPT_FAILED,
        OK      = 0
    } PACKED;

    class Script
    {
    private:
        char *m_script;
        int   m_handler   = -1;
        bool  m_isCreated = false;

    public:
        Script(const char *script);

        ScriptStatus status();
        ScriptStatus status(unsigned int *parameters);

        bool run();
        bool run(unsigned int numberOfParameters, unsigned int *parameters);

        bool stop(bool remove);

        bool remove();

        bool isCreated() const;
    };
}

#endif
