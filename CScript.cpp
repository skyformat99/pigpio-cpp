/*
 * Author: Erdet Nasufi <erdet.nasufi@gmail.com>
 */

#include "CScript.h"

using namespace pigpio_wcpp;

Script::Script(const char *script)
{
    if(script == NULL) return;

    int len_ = strlen(script);
    m_script = new char[len_ + 1];
    strcpy(m_script, script);
    m_script[len_] = 0;

    m_handler = gpioStoreScript(m_script);

    if(m_handler > -1)
        m_isCreated = true;
}

ScriptStatus Script::status()
{
    return (ScriptStatus)gpioScriptStatus(m_handler, NULL);
}

ScriptStatus Script::status(unsigned int *parameters)
{
    return (ScriptStatus)gpioScriptStatus(m_handler, parameters);
}

bool Script::run()
{
    return (gpioRunScript(m_handler, 0, NULL) == 0);
}

bool Script::run(unsigned int numberOfParameters, unsigned int *parameters)
{
    return (gpioRunScript(m_handler, numberOfParameters, parameters) == 0);
}

bool Script::stop(bool remove)
{
    bool ret_ = gpioStopScript(m_handler) > -1;
    if(remove)
    {
        ret_ &= gpioDeleteScript(m_handler) > -1;
    }
    return ret_;
}

bool Script::remove()
{
    return (gpioDeleteScript(m_handler) > -1);
}
