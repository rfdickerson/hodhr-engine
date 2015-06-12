#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "texture.h"
#include "color.h"

namespace Hodhr {

class Texture2D : public Texture
{
public:

    Texture2D(int width, int height);
    Texture2D(int width, int height,
              TextureFormat format, bool mipmap, bool linear);

    virtual ~Texture2D();

    // static functions
    static Texture2D blackTexture();
    static Texture2D whiteTexture();

    bool loadImage(std::vector<char> data);

    void compress(bool highQuality);

    void loadRawTextureData(std::vector<unsigned char> data);

    int mipmapCount() const;

    void setPixel(int x, int y, Color color);

    void setPixels(std::vector<Color> colors, int miplevel = 0);

    void updateExternalTexture(int nativeTex);

    void apply();


private:
    int m_mipmapCount;
    TextureFormat m_format;
    bool m_mipmap;
    bool m_linear;

    std::vector<unsigned char> m_rawTextureData;


};

}

#endif // TEXTURE2D_H
