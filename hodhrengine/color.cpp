#include "color.h"

#include <memory>

using namespace Hodhr;

Color::Color()
    : mGamma(2.2f), mColorData(1,1,1,1)
{

}

Color::Color(float r, float g, float b, float a)
    : mGamma(2.2f), mColorData(r,g,b,a)
{

}


Color::Color(const Color& c)
{
    mColorData = c.mColorData;
    mGamma = c.mGamma;
}

Color& Color::operator=(const Color& other)
{
    mColorData = other.mColorData;
    mGamma = other.mGamma;

    return *this;
}

Color::~Color()
{

}

Color Color::Yellow()
{
    return Color(1.0f,0.92f,0.016f,1.0f);
}

Color Color::Pink()
{
    return Color(1,0.078f,0.576f,1.0f);
}

Color Color::LightGrey()
{
    return Color(.75,.75,.75,1.0f);
}

Color Color::DarkGrey()
{
    return Color(.35,.35,.35,1.0f);
}

Color Color::Red()
{
    return Color(1.0, 0.0,0.0,1.0f);
}

 Color Color::Green()
 {
     return Color(0.0, 1.0, 0.0, 1.0f);
 }

 Color Color::Blue()
 {
     return Color(0.0f, 0.0f, 1.0f, 1.0f);
 }


float Color::red() const
{
    return mColorData.r;
}

float Color::green() const
{
    return mColorData.g;
}

float Color::blue() const
{
    return mColorData.b;
}

float Color::alpha() const
{
    return mColorData.a;
}


