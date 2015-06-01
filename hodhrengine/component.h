#ifndef COMPONENT_H
#define COMPONENT_H

#include "object.h"
#include "transform.h"
#include "gameobject.h"

#include <string>

namespace Hodhr {

    class Component : public Object
    {
    public:

        typedef enum {
            REQUIRE_RECEIVER,
            DONT_REQUIRE_RECEIVER
        } SendMessageOptions;


        Component(const GameObject& gameObject);
        virtual ~Component();

        void BroadcastMessage(const std::string& methodName, SendMessageOptions options);

        template<class T> T* GetComponent() const;

        template<class T>
        std::vector<T*> GetComponents() const;

        void SendMessage(const std::string& methodName, Object* object = NULL );

        void SendMessageUpwards();

        Transform & transform() ;

        template<class T>
        T* AddComponent()
        {
            T* comp = NULL;
            comp = new T(*this);

            if (comp != NULL) {
                mGameObject.getComponents().push_back(comp);
            }


            return comp;
        }

        template<class T>
        T* GetComponent()  {
            std::vector<Component*>::const_iterator it;

            for (it = mGameObject.getComponents().begin();
                 it != mGameObject.getComponents().end(); it++)
            {
                if (T* v = dynamic_cast<T*>(*it)) {

                    return v;
                }

            }

            // could not find the component.
            return NULL;
        }


    protected:

        // members
        Transform mTransform;

        const GameObject &mGameObject;

        std::string mTag;


    };

}

#endif // COMPONENT_H
