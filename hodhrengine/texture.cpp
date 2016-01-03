#include "object.hpp"
#include "texture.hpp"

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

