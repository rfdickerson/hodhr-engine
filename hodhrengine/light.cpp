#include "light.h"
#include "behavior.h"

using namespace Hodhr;


Light::Light(const GameObject& gameObject)
    : Behavior(gameObject)
{

}

Light::~Light()
{

}

void Light::setColor(Color color)
{
    mColor = color;
}
