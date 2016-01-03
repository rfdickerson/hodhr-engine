#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include "renderer.hpp"

namespace Hodhr {

/**
 * @brief The MeshRenderer takes the geometry from the Mesh Filter and
 * renders it at the position defined by the Object's Transform component.
 */
class MeshRenderer : public Renderer
{
public:
    MeshRenderer(const GameObject& gameObject);
    ~MeshRenderer();



};

}

#endif // MESHRENDERER_H
