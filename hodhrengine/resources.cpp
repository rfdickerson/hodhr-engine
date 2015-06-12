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
     const ImageSpec &spec = in->spec();
     int xres = spec.width;
     int yres = spec.height;
     int channels = spec.nchannels;
     std::vector<unsigned char> pixels (xres*yres*channels);


     in->read_image( TypeDesc::UINT8, &pixels[0]);
     in->close ();

     Texture2D * newTexture = new Texture2D(xres, yres);

     char out[80];
     sprintf(out, "Created new texture of size %dx%d with %d channels.", xres, yres, channels);
     Debug::log(out, NULL);

     newTexture->loadRawTextureData(pixels);
     newTexture->apply();


    return newTexture;
}
