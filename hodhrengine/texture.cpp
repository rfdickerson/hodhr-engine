#include "object.h"
#include "texture.h"

using namespace Hodhr;

Texture::Texture()
{

}

Texture::~Texture()
{

}

int Texture::nativeTextureID() const
{
    return m_nativeTextureID;
}

