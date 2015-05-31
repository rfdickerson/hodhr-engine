#include "rendertexture.h"

#define GLEW_STATIC
#include "GL/glew.h"

using namespace Hodhr;

// static variables initializion

RenderTexture * RenderTexture::mActive = NULL;

RenderTexture::RenderTexture(int width, int height, int depth)

{
 this->width = width;
 this->height = height;
 this->depth = depth;
}

RenderTexture::~RenderTexture()
{

}

/**
 * @brief RenderTexture::create
 *
 * Actually creates the RenderTexture
 *
 * @return
 */
bool RenderTexture::create()
{

    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);

    glGenTextures(5, textures);
    glGenTextures(1, &depthTexture);

    for (unsigned int i = 0; i < 5; i++)
    {
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, width, height, 0, GL_RGB, GL_FLOAT, NULL);
        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, textures[i], 0);
    }

    // depth
    glBindTexture(GL_TEXTURE_2D, depthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture, 0);

    GLenum DrawBuffers[] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
    glDrawBuffers(5, DrawBuffers);

    return true;
}

void RenderTexture::release()
{
    glDeleteTextures(5, textures);
    glDeleteTextures(1, &mNativeTextureID);

    glDeleteFramebuffers(1, &fbo);
}

/**
 * @brief RenderTexture::getTemporary
 *
 * Allocate a temporary render texture.
 *
 * This function is optimized for when you need a quick RenderTexture to do some temporary
 * calculations. Release it using ReleaseTemporary as soon as you're done with it, so another
 * call can start reusing it if needed.
 *
 * Internally Hodhr keeps a pool of temporary render textures, so a call to GetTemporary most
 * often just returns an already created one (if the size and format matches). These temporary
 * render textures are actually destroyed when they aren't used for a couple of frames.
 *
 * If you are doing a series of post-processing "blits", it's best for
 * performance to get and release a temporary render texture for each blit, instead of getting one
 * or two render textures upfront and reusing them.
 *
 * You can not depend on any particular contents of the
 * RenderTexture you get from GetTemporary function. It might be garbage, or it might be cleared
 * to some color, depending on the platform.
 *
 * @param width
 * @param height
 * @param depthBuffer
 * @param format
 * @param readWrite
 * @param antialiasing
 * @return
 */
RenderTexture * RenderTexture::getTemporary(int width,
                                            int height,
                                            int depthBuffer,
                                            RenderTextureFormat format,
                                            RenderTextureReadWrite readWrite,
                                            int antialiasing)
{

    // check to see if it is already available.


    RenderTexture *rt = new RenderTexture(width, height, depthBuffer);



    return rt;
}

/**
 * @brief Release a temporary texture allocated with GetTemporary
 *
 * Later calls to GetTemporary will reuse the RenderTexture created earlier if possible.
 * When no one has requested the temporary RenderTexture for a few frames it will be destroyed.
 *
 * @param temp
 */
void RenderTexture::releaseTemporary(const RenderTexture & temp)
{

}

void RenderTexture::bindForWriting()
{
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);
}

void RenderTexture::bindForReading()
{
    glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);
}

RenderTexture * RenderTexture::active()
{
    return mActive;
}

void RenderTexture::setActive( RenderTexture * rt)
{

    mActive = rt;

}
