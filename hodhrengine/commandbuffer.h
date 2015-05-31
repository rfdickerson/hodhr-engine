#ifndef COMMANDBUFFER_H
#define COMMANDBUFFER_H

#include <string>

namespace Hodhr {

namespace Rendering {

class CommandBuffer
{
public:
    CommandBuffer();


private:
    std::string mName;
    long sizeInBytes;
};

} // end rendering namespace

}

#endif // COMMANDBUFFER_H
