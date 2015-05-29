#include "qtdebugconsole.h"

#include <QString>
#include <QTextEdit>

QtDebugConsole::QtDebugConsole()
{

}

QTextEdit * QtDebugConsole::logEdit = NULL;

void QtDebugConsole::addLog(const std::string & type, const std::string & mesg )
{
    if (logEdit == NULL)
        return;

    // QTextStream out(stdout);
    QString out = "<b>";
    out += QString(type.c_str());
    out += ":</b> ";
    out += mesg.c_str();

    logEdit->append(out);
}

void QtDebugConsole::setLogBuffer(const QTextEdit & editText)
{
    logEdit = (QTextEdit*) &editText;
}
