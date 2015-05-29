#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "component.h"

namespace Hodhr {

    class Behavior : public Component
    {
    public:

        Behavior(const GameObject& gameObject);
        virtual ~Behavior();

        bool enabled;
        bool isActiveAndEnabled();
    };

}

#endif // BEHAVIOR_H
