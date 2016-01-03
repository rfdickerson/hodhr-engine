#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "object.hpp"
// #include "transform.h"
// #include "component.h"

#include <string>

namespace Hodhr {

    typedef enum {

        GAMEOBJECT_SPHERE,
        GAMEOBJECT_QUAD,
        GAMEOBJECT_CUBE

    } PrimitiveType;

    class Component;
    class Transform;


    class GameObject : public Object
    {
    public:
        GameObject(const std::string& name);
        ~GameObject();

        std::vector<Component * > getComponents() const;

        Transform * transform() const;

        static GameObject* createFromFile(const std::string & path);

        static GameObject* createPrimitive(PrimitiveType type);

        static std::vector<GameObject*> findGameObjectsWithTag(const std::string& tag);

        template<class T>
        T* AddComponent()
        {
            T* comp = NULL;
            comp = new T(*this);

            if (comp != NULL) {
                mComponents.push_back(comp);
            }


            return comp;
        }

        template<class T>
        T* GetComponent()  {
            std::vector<Component*>::const_iterator it;

            for (it = mComponents.begin(); it != mComponents.end(); it++)
            {
                if (T* v = dynamic_cast<T*>(*it)) {

                    return v;
                }

            }

            // could not find the component.
            return NULL;
        }



    protected:

        int layer;

        // The Transform attached to this GameObject. (null it there is none attached).
        Transform *mTransform;

        std::string mTag;

        bool mActive;

        /**
         * @brief All of the attached components.
         */
        std::vector<Component*> mComponents;


    };

} // end namespace Hodhr

#endif // GAMEOBJECT_H
