#include "object.h"
#include "debug.h"

using namespace Hodhr;

// Define static vector of all objects
std::vector<Object> Object::allObjects;


Object::Object()
{
    allObjects.push_back(*this);

    if (Debug::getInstance()) {
        Debug::getInstance()->addLog("Object", "Added the object");
    }
}

Object::~Object()
{

}

std::string Object::toString() const
{
    return name;
}

void Object::Destroy(Object * object){
    // allObjects.remove(object);
}

/**
std::vector<const Object*> Object::findObjectsOfTypeAll(ObjectType type)
{
    std::vector<const Object*> o;

    std::vector<Object>::const_iterator it;

    for (it = allObjects.begin();it!=allObjects.end();it++)
    {
        const Object *object = &(*it);
        o.push_back(object);
    }

    return o;
}
**/
