#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "object.h"
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

        /**
         * @brief Creates a game object with a primitive mesh renderer
         * @param type
         * @return
         */
        static GameObject* createPrimitive(PrimitiveType type);

        static std::vector<GameObject*> findGameObjectsWithTag(const std::string& tag);

        /**
         * @brief Adds a component named className to the game object.
         * @param className
         * @return
         */
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

        Transform * transform() const;

    private:

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
