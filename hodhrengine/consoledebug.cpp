#include "consoledebug.h"

#include <stdio.h>

ConsoleDebug::ConsoleDebug()
{

}

ConsoleDebug::~ConsoleDebug()
{

}

void ConsoleDebug::addLog(const std::string & type, const std::string & mesg )
{
    fprintf(stderr, "%s: %s\n", type.c_str(), mesg.c_str());
}
