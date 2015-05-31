#include "renderer.h"
#include "component.h"
#include "materialpropertyblock.h"

using namespace Hodhr;

/**
 * General functionality for all renderers.
 *
 * A renderer is what makes an object appear on the screen. Use this
 * class to access the renderer of any object, mesh, or particle system.
 * Renderers can be disabled to make objects invisible (see enabled), and
 * the materials can be accessed and modified through them (see material).
 *
 */

Renderer::Renderer(const GameObject& gameObject)
    : Component(gameObject),
      mEnabled(true) // call super class
{

}

Renderer::~Renderer()
{

}

Material * Renderer::material() const
{
    return mMaterial;
}

void Renderer::setMaterial(Material * mat)
{
    mMaterial = mat;
}

/**
 * @brief Makes the renderered 3D object visible if enabled.
 * @return
 */
bool Renderer::enabled() const
{
    return mEnabled;
}

void Renderer::setEnabled(bool enabled)
{
    mEnabled = enabled;
}
