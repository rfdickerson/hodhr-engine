#ifndef RENDERTEXTURE_H
#define RENDERTEXTURE_H

#include "texture.h"
#include "renderbuffer.h"

namespace Hodhr {

typedef enum {
    RenderFormatARGB32,
    RenderFormatDepth,
    RenderFormatDefault,
    RenderFormatDefaultHDR
} RenderTextureFormat;

typedef enum {
    RenderTextureRWDefault,
    RenderTextureRWLinear,
    RenderTextureRWsRGB
} RenderTextureReadWrite;


class RenderTexture : public Texture
{
public:

    enum GBUFFER_TEXTURE_TYPE {
            GBUFFER_TEXTURE_TYPE_POSITION,
            GBUFFER_TEXTURE_TYPE_DIFFUSE,
            GBUFFER_TEXTURE_TYPE_NORMAL,
            GBUFFER_TEXTURE_TYPE_TEXCOORD,
            GBUFFER_NUM_TEXTURES
        };

    RenderTexture(int width, int height, int depth);
    ~RenderTexture();

    bool create();

    // Releases the hardware resources used by the render texture.
    void release();

    void discardContents();

    void bindForWriting();

    void bindForReading();

    static RenderTexture * getTemporary(int width, int height, int depthBuffer=0);

    static RenderTexture * active;

    RenderBuffer colorBuffer;

    /**
     * @brief The precision of the render texture's depth buffer in bits (0, 16, 24 are supported).
     */
    int depth;

    /**
     * @brief Depth/stencil buffer of the render texture.
     */
    RenderBuffer depthBuffer;

    /**
     * @brief Does this render texture use sRGB read/write?
     */
    bool sRGB;

    /**
     * @brief Use mipmaps on a render texture?
     */
    bool useMipMap;

    /**
     * @brief The width of the render texture in pixels.
     */
    int width;

    /**
     * @brief The height of the render texture in pixels.
     */
    int height;

    RenderTextureFormat format;
    RenderTextureReadWrite readWrite;

protected:

    std::vector<float> data;

    GLuint fbo;
    GLuint textures[GBUFFER_NUM_TEXTURES];
    GLuint depthTexture;
};

}

#endif // RENDERTEXTURE_H
