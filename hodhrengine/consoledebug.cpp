#include "consoledebug.hpp"

#include <stdio.h>

using namespace Hodhr;

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
