#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "renderbuffer.h"
#include "texture.h"
#include "mesh.h"
#include "rendertexture.h"
#include "material.h"
#include "rect.h"
#include "camera.h"
#include "commandbuffer.h"

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

    static RenderBuffer * activeColorBuffer();
    static RenderBuffer * activeDepthBuffer();

    static void blit(const Texture & source, const RenderTexture & dest);
    static void blit(const Texture & source, const RenderTexture & dest,
                     const Material & mat,
                     int pass=-1);
    static void blit(const Texture & source,
                     const Material & mat,
                     int pass=-1);

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

    static void executeCommandBuffer(const Rendering::CommandBuffer & buffer);

private:

    static RenderBuffer *mActiveColorBuffer;
    static RenderBuffer *mActiveDepthBuffer;

};

}

#endif // GRAPHICS_H
