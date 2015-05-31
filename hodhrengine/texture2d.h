#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "texture.h"

namespace Hodhr {

class Texture2D : public Texture
{
public:
    Texture2D(int width, int height);
    ~Texture2D();

    static Texture2D blackTexture();

    void compress(bool highQuality);

    void loadRawTextureData(char * data);

};

}

#endif // TEXTURE2D_H
