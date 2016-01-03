#ifndef SCENE_H
#define SCENE_H

#include "object.hpp"

#include <vector>

namespace Hodhr {

    // forward defines
    class GameObject;
    class Light;

    class Scene : public Object
    {
    public:
        Scene();

        void AddGameObject(GameObject *gameObject);

        void AddCamera();

        void Render();

        std::vector<GameObject*> GetGameObjects() const;

        static Scene* GetCurrent();
        static void SetCurrent(Scene *scene);


        std::vector<GameObject *> mGameObjects;

        static Scene* currentScene;


    };

}

#endif // SCENE_H
