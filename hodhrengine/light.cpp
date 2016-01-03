#include "light.hpp"
#include "behavior.hpp"

using namespace Hodhr;


Light::Light(const GameObject& gameObject)
    : Behavior(gameObject),
      mIntensity(1.0f),
      mColor(1.0,1.0,1.0),
      mRange(10.0f)
{

}

Light::~Light()
{

}

void Light::setColor(Color color)
{
    mColor = color;
}

float Light::intensity() const
{
    return mIntensity;
}

float Light::shadowStrength() const
{
    return mShadowStrength;
}

float Light::range() const
{
    return mRange;
}

Light::LightType Light::lightType() const
{
    return mLightType;
}

Light::LightShadows Light::lightShadows() const
{
    return mLightShadows;
}

Light::LightRenderMode Light::renderMode() const
{
    return mRenderMode;
}
