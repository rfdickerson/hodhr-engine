#ifndef QTDEBUGCONSOLE_H
#define QTDEBUGCONSOLE_H

#include "debug.h"

class QTextEdit;

class QtDebugConsole : public Debug
{
public:
    QtDebugConsole();

    static QTextEdit * logEdit;

    void addLog(const std::string & type, const std::string & mesg );

    static void setLogBuffer(const QTextEdit & editText);
};

#endif // QTDEBUGCONSOLE_H
