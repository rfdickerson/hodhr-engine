#include "meshrenderer.hpp"
#include "debug.hpp"
#include "gameobject.hpp"
#include "graphics.hpp"

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

