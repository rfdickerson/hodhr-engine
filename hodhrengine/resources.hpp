#ifndef RESOURCES_H
#define RESOURCES_H

#include "object.hpp"
#include "shader.hpp"
#include "mesh.hpp"
#include "texture2d.hpp"

#include <string>

namespace Hodhr {

    class Resources
    {
    public:

        static Object* Load(const std::string& path);

        static std::string LoadFile(const std::string& path);

        static Shader* LoadShader(const std::string& path);

        static Mesh* LoadMesh(const std::string& path);

        static Texture2D * LoadTexture(const std::string & path);
    };

}

#endif // RESOURCES_H
