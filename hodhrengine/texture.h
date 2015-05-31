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
    int nativeTextureID() const;

protected:

    unsigned int mNativeTextureID;

    int mAnisoLevel;
    FilterMode mFilterMode;

    int mHeight;
    int mWidth;
    int mDepth;

    TextureWrapMode wrapMode;

};

}

#endif // TEXTURE_H
