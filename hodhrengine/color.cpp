#include "color.h"

#include <memory>

using namespace Hodhr;

Color::Color()
    : gamma(2.2f), colorData(1,1,1,1)
{

}

Color::Color(float r, float g, float b, float a)
    : gamma(2.2f), colorData(r,g,b,a)
{

}

Color::Color(const Color& c)
{
    colorData = c.colorData;
    gamma = c.gamma;
}

Color& Color::operator=(const Color& other)
{
    colorData = other.colorData;
    gamma = other.gamma;

    return *this;
}

Color::~Color()
{

}

Color Color::yellow()
{
    return Color(1.0f,0.92f,0.016f,1.0f);
}

Color Color::pink()
{
    return Color(1,0.078f,0.576f,1.0f);
}

Color Color::lightGrey()
{
    return Color(.75,.75,.75,1.0f);
}

Color Color::darkGrey()
{
    return Color(.35,.35,.35,1.0f);
}

Color Color::red()
{
    return Color(1.0, 0.0,0.0,1.0f);
}

 Color Color::green()
 {
     return Color(0.0, 1.0, 0.0, 1.0f);
 }

 Color Color::blue()
 {
     return Color(0.0f, 0.0f, 1.0f, 1.0f);
 }


float Color::getRed() const
{
    return colorData.r;
}

float Color::getGreen() const
{
    return colorData.g;
}

float Color::getBlue() const
{
    return colorData.b;
}

float Color::getAlpha() const
{
    return colorData.a;
}


