#include "scene.hpp"
#include "gameobject.hpp"
#include "meshrenderer.hpp"
#include "camera.hpp"
#include "debug.hpp"

#include <vector>

using namespace Hodhr;

Scene* Scene::currentScene = NULL;

Scene::Scene()
{

}

Scene* Scene::GetCurrent()
{
    return currentScene;
}

void Scene::SetCurrent(Scene *scene)
{
    currentScene = scene;
}

void Scene::AddGameObject(GameObject *gameObject)
{
    mGameObjects.push_back(gameObject);
}

void Scene::Render()
{

    std::vector<GameObject*>::iterator it;

    for (it=mGameObjects.begin();it!=mGameObjects.end();it++)
    {
        GameObject *o = (*it);
        Camera *c = o->GetComponent<Camera>();
        if (c != NULL) {

            c->render();
        }

    }

}

std::vector<GameObject*> Scene::GetGameObjects() const
{
    // std::vector<GameObject*> copy = mGameObjects;
    return mGameObjects;
}

