#ifndef DISPLAY_H
#define DISPLAY_H

#include "renderbuffer.h"

#include <vector>

namespace Hodhr {

class Display
{
public:
    Display();
    ~Display();

    /**
     * @brief The list of currently connected Displays.
     */
    static std::vector<Display> displays;
    static Display* main;

    RenderBuffer colorBuffer;
    RenderBuffer depthBuffer;

    int renderingHeight;
    int renderingWidth;


    void setRenderingResolution(int w, int h);


};

}

#endif // DISPLAY_H
