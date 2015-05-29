#ifndef COMPONENT_H
#define COMPONENT_H

#include "object.h"
#include "transform.h"
// #include "gameobject.h"

#include <string>

namespace Hodhr {


    class GameObject;



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


    private:

        // members
        Transform mTransform;

        const GameObject &gameObject;


        std::string mTag;


    };

}

#endif // COMPONENT_H
