#ifndef CONSOLEDEBUG_H
#define CONSOLEDEBUG_H

#include "debug.h"

class ConsoleDebug : public Debug
{
public:
    ConsoleDebug();
    ~ConsoleDebug();

     virtual void addLog(const std::string & type, const std::string & mesg );
};

#endif // CONSOLEDEBUG_H
