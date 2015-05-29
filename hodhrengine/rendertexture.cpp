#include "rendertexture.h"

#define GLEW_STATIC
#include "GL/glew.h"

using namespace Hodhr;

// static variables initializion

RenderTexture * RenderTexture::active;

RenderTexture::RenderTexture(int width, int height, int depth)

{
 this->width = width;
 this->height = height;
 this->depth = depth;
}

RenderTexture::~RenderTexture()
{

}

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
    glDeleteTextures(1, &textureID);

    glDeleteFramebuffers(1, &fbo);
}

RenderTexture * RenderTexture::getTemporary(int width, int height, int depthBuffer)
{
    RenderTexture *rt = new RenderTexture(width, height, depthBuffer);

    return rt;
}

void RenderTexture::bindForWriting()
{
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);
}

void RenderTexture::bindForReading()
{
    glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);
}
