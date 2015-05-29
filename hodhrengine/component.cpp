#include "object.h"
#include "component.h"
#include "gameobject.h"
#include "transform.h"

using namespace Hodhr;

Component::Component(const GameObject& gameObject)
    : gameObject(gameObject)
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

