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


    void setDepth(int depth) {
        m_depth = depth;
    }


protected:

    unsigned int m_nativeTextureID;

    int m_anisoLevel;
    FilterMode mFilterMode;

    int m_height;
    int m_width;
    int m_depth;

    TextureWrapMode m_wrapMode;

};

}

#endif // TEXTURE_H
