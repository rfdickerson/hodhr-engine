#ifndef MESH_H
#define MESH_H

#include "common.h"
#include "color.h"
#include "object.h"


#include <glm/glm.hpp>
#include <vector>

namespace Hodhr {


    class Mesh : public Object
    {
    public:
        Mesh();
        ~Mesh();


        GLuint vao() const;

        void recalculateTangents();

        std::vector<Color> colors;

        std::vector<glm::vec3> tangents;

        std::vector<glm::vec3> bittangents;

        std::vector<glm::vec3> normals;

        std::vector<unsigned short> triangles;

        std::vector<glm::vec2> uvs;

        std::vector<glm::vec3> vertices;

        GLuint mVAO;
        //GLuint mVBO[1];
        //GLuint mVIndex[1];

        // std::vector<HodhrVertex> hvertices;



    };

}

#endif // MESH_H
