#include "resources.h"
#include "debug.h"

#include <cstring>
#include <string>
#include <fstream>
#include <utility>
#include <cerrno>

#include <OpenImageIO/imageio.h>
OIIO_NAMESPACE_USING

using namespace Hodhr;

Object* Resources::Load(const std::string& path)
{
    return NULL;
}

std::string Resources::LoadFile(const std::string& filename)
  {
    std::ifstream in(filename, std::ios::in | std::ios::binary);

    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }

    throw(errno);
}

Shader* Resources::LoadShader(const std::string& path)
{
    std::string shaderSrc;

    shaderSrc = LoadFile(path);

    Shader *shader;

    shader = new Shader(shaderSrc);

    return shader;

}

Mesh* Resources::LoadMesh(const std::string& path)
{
    return NULL;
}

Texture2D * Resources::LoadTexture(const std::string & path)
{

    ImageInput *in = ImageInput::open( path );
     //ImageInput *in = ImageInput::open( path );
     if (! in )
         return NULL;
     ImageSpec spec = in->spec();
     int xres = spec.width;
     int yres = spec.height;
     int channels = spec.nchannels;
     std::vector<unsigned char> pixels (4*xres*yres*channels);

     int num_miplevels = 0;
     long count = 0;

     while (in->seek_subimage(0, num_miplevels, spec)) {


         int sheight = spec.height;
         int swidth = spec.width;
         //xres = spec.width;
         //yres = spec.height;
         int size = spec.height * spec.width * channels;

         std::vector<unsigned char> subimagepixels (sheight*swidth*channels);

         in->read_image( TypeDesc::UINT8, &subimagepixels[0]);

         pixels.insert(pixels.begin()+count, subimagepixels.begin(), subimagepixels.end());

         ++num_miplevels;
         count += size;
     }

     in->close ();

     Texture2D * newTexture = new Texture2D(xres, yres);

     char out[80];
     sprintf(out, "Created new texture of size %dx%d with %d channels, %d miplevels.", xres, yres, channels, num_miplevels);
     Debug::log(out, NULL);

     newTexture->setDepth(channels);
     newTexture->setMipmapCount(num_miplevels);
     newTexture->loadRawTextureData(pixels);
     newTexture->apply();


    return newTexture;
}
