#include "meshrenderer.h"
#include "debug.h"
#include "gameobject.h"
#include "graphics.h"

using namespace Hodhr;

MeshRenderer::MeshRenderer(const GameObject& gameObject)
    : Renderer(gameObject)
{
     if (Debug::getInstance()) {
        Debug::getInstance()->addLog("Components", "Added the Mesh renderer component");
     }

    //mTag = "Mesh Renderer";
}

MeshRenderer::~MeshRenderer()
{

}

