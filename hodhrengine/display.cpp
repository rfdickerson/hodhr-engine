#include "display.hpp"

#include <vector>

using namespace Hodhr;

std::vector<Display> Display::displays;



Display::Display()
{

    displays.push_back(*this);

}

Display::~Display()
{

}

void Display::setRenderingResolution(int w, int h)
{
    renderingWidth = w;
    renderingHeight = h;
}

/**
 * @brief Activate an external display. Eg. Secondary Monitors connected to the System
 */
void Display::activate()
{

}
