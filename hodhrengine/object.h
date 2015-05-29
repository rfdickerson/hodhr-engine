#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include <memory>

namespace Hodhr {



class Object
{
public:

    Object();
    virtual ~Object();

    std::string toString() const;
    int getInstanceID();

    //static Object findObjectOfType(ObjectType type);
    static void Destroy(Object *);
    static Object * Instantiate(Object*);

    static std::vector<Object> allObjects;

    // static std::vector<const Object*> findObjectsOfTypeAll(ObjectType type);

protected:

    // The name of the object.
    std::string name;

    // const ObjectType type;

    int instanceID;
};

}

#endif // OBJECT_H
