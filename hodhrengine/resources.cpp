#include "resources.h"
#include "debug.h"

#include <cstring>
#include <string>
#include <fstream>
#include <utility>
#include <cerrno>

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
