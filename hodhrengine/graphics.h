#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "renderbuffer.h"
#include "texture.h"
#include "mesh.h"
#include "rendertexture.h"
#include "material.h"
#include "rect.h"
#include "camera.h"

#define GLEW_STATIC
#include "GL/glew.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

namespace Hodhr {

class Graphics
{
public:
    Graphics();
    ~Graphics();

    static RenderBuffer *activeColorBuffer;
    static RenderBuffer *activeDepthBuffer;

    static void blit(Texture *source, Texture *dest);

    /**
     * @brief drawMesh
     * @param mesh The Mesh to draw.
     * @param position Position of the mesh.
     * @param rotation Rotation of the mesh.
     */
    static void drawMesh(const Mesh & mesh,
                         const glm::vec3 & position,
                         const glm::quat & rotation,
                         const Material & mat,
                         int layer = 0,
                         const Camera * camera = NULL,
                         int submeshIndex = 0,
                         const MaterialPropertyBlock * properties = NULL,
                         bool castShadows = true,
                         bool receiveShadows = true
                         );

    static void uploadMesh( Mesh *mesh );

    static void removeMesh( Mesh *mesh );


    static void drawTexture(const Rect& screenRect, const Texture& texture, const Material& mat);

    static void setRenderTarget(RenderTexture *rt);

    static void checkErrors(const std::string & label);

};

}

#endif // GRAPHICS_H
