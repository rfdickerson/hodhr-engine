#ifndef RENDERTEXTURE_H
#define RENDERTEXTURE_H

#include "texture.hpp"
#include "renderbuffer.hpp"

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

    // Discards the contents of the RenderTexture.
    void discardContents();

    // Is the render texture actually created?
    bool isCreated();

    // added by me
    void bindForWriting();
    void bindForReading();

    static RenderTexture * getTemporary(int width,
                                        int height,
                                        int depthBuffer=0,
                                        RenderTextureFormat format=RenderFormatDefault,
                                        RenderTextureReadWrite readWrite = RenderTextureRWDefault,
                                        int antialiasing = 1);

    static void releaseTemporary(const RenderTexture & temp);

    static RenderTexture * active();
    static void setActive(RenderTexture * rt);

    // precision of the render texture.
    int depth;

    RenderBuffer colorBuffer;

    // Depth/stencil buffer of the render texture
    RenderBuffer depthBuffer;

    bool sRGB;

    bool useMipMap;

    int width;

    int height;

    RenderTextureFormat format;
    RenderTextureReadWrite readWrite;

protected:

    bool mCreated;

    static RenderTexture * mActive;
    static RenderBuffer * mActiveColorBuffer;
    static RenderBuffer * mActiveDepthBuffer;

    static

    std::vector<float> data;

    GLuint fbo;
    GLuint textures[GBUFFER_NUM_TEXTURES];
    GLuint depthTexture;
};

}

#endif // RENDERTEXTURE_H
