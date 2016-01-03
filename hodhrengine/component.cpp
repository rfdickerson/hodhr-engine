#include "object.hpp"
#include "component.hpp"
#include "gameobject.hpp"
#include "transform.hpp"

using namespace Hodhr;

Component::Component(const GameObject& gameObject)
    : mGameObject(gameObject)
{
    //mTransform = new Transform();
}

Component::~Component()
{
    //delete mTransform;
}

Transform & Component::transform()
{
    return mTransform;
}

