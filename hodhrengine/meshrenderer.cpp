#include "meshrenderer.h"
#include "debug.h"
#include "gameobject.h"
#include "graphics.h"

using namespace Hodhr;

MeshRenderer::MeshRenderer(const GameObject& gameObject)
    : Renderer(gameObject)
{

    Debug::log("Added the Mesh renderer component", this);


    //mTag = "Mesh Renderer";
}

MeshRenderer::~MeshRenderer()
{

}

