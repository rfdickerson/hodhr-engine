#ifndef DEBUG_H
#define DEBUG_H

#include <string>

#include "common.hpp"
#include "object.hpp"

namespace Hodhr {

class Debug
{
public:
    Debug();
    virtual ~Debug();

    //static QTextEdit * logEdit;

    static Debug * mInstance;

    static Debug * getInstance()
    {
        return mInstance;
    }

    static void setInstance(Debug * instance) {
        mInstance = instance;
    }

    virtual void addLog(const std::string & type, const std::string & mesg ) = 0;

    static void deleteInstance()
    {
        if (mInstance) {
            delete mInstance;
        }
    }

    static void log(const std::string &mesg, Object * context)
    {
        if (getInstance() != NULL) {

            std::string ctxString = "";

            if (context != NULL ) {
                ctxString = context->toString();
            }

            getInstance()->addLog(ctxString, mesg);
        }
    }

    static void log(const std::string & type, const std::string & mesg)
    {
        if (getInstance() != NULL) {
            getInstance()->addLog(type, mesg);
        }
    }

    //static void setLogBuffer(const QTextEdit & editText);
};

}

#endif // DEBUG_H
