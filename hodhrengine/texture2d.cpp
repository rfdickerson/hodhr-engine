#include "texture2d.h"

using namespace Hodhr;

Texture2D::Texture2D(int w, int h)
{

    mWidth = w;
    mHeight = h;
}

Texture2D Texture2D::blackTexture()
{
    return Texture2D(128,128);
}

/**
 * @brief Texture2D::compress
 *
 * Compress texture into DXT format.
 *
 * Use this to compress textures generated at runtime. Compressed textures
 * use less graphics memory and are faster to render.
 *
 * After compression, texture will be in DXT1 format if the original texture
 * had no alpha channel, and in DXT5 format if it had alpha channel.
 *
 * Passing true for highQuality parameter will dither the source texture
 * during compression, which helps to reduce compression artifacts but is
 * slightly slower.
 *
 * If the graphics card does not support compression or the texture is already
 * in comrpessed format, then Compress will do nothing.
 *
 * @param highQuality
 */
void Texture2D::compress(bool highQuality)
{

}

/**
 * @brief Texture2D::loadRawTextureData
 *
 * Fills texture pixels with raw preformatted data.
 *
 * This function fills texture pixel memory with raw data. This
 * is mostly useful for loading compressed texture format data into
 * a texture.
 *
 * Passed data should be of required size to fill the whole texture
 * according to its width, height, data format and mipmapCount. Mipmaps
 * are laid out in memory starting from largest, with smaller mip level
 * data immediately following.
 *
 * For example, a 16x8 texture of ARGB32 type with no mipmaps can be filled
 * with a 512-byte array (16x8x4)
 *
 * Call Apply after setting image data to actually upload it to the GPU.
 *
 * @param data
 */
void Texture2D::loadRawTextureData(char * data)
{

}
