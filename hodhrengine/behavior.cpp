#include "behavior.hpp"

using namespace Hodhr;

Behavior::Behavior(const GameObject& gameObject)
    : Component(gameObject)
{

}

Behavior::~Behavior()
{

}

bool Behavior::isActiveAndEnabled()
{
    return enabled;
}

