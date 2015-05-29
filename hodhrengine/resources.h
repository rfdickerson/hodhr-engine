#ifndef RESOURCES_H
#define RESOURCES_H

#include "object.h"
#include "shader.h"
#include "mesh.h"

#include <string>

namespace Hodhr {

    class Resources
    {
    public:

        static Object* Load(const std::string& path);

        static std::string LoadFile(const std::string& path);

        static Shader* LoadShader(const std::string& path);

        static Mesh* LoadMesh(const std::string& path);
    };

}

#endif // RESOURCES_H
