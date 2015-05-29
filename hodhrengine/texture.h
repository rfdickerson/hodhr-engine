#ifndef TEXTURE_H
#define TEXTURE_H

#define GLEW_STATIC
#include "GL/glew.h"

#include "object.h"

namespace Hodhr {

typedef enum {
    TextureFloat,
    TextureByte
} TextureFormat;

typedef enum {
    FilterModePoint,
    FilterModeBilinear,
    FilterModeTrilinear
} FilterMode;

typedef enum {
    WrapModeRepeat,
    WrapModeClamp
} TextureWrapMode;

/**
 * @brief Base class for texture handling.
 */
class Texture : public Object
{
public:

    Texture();
    virtual ~Texture();

    // Retrieve native (hardware) handle to texture. (read only)
    int getNativeTextureID();

    int anisoLevel;
    FilterMode filterMode;

    int height;
    int width;
    int depth;

    TextureWrapMode wrapMode;

protected:

    unsigned int textureID;

};

}

#endif // TEXTURE_H
