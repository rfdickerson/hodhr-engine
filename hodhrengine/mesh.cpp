#include "object.h"
#include "mesh.h"

using namespace Hodhr;

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::recalculateTangents()
{
    // calculate the tangents, and bittangents.

    for (int i=0;i<vertices.size();i+=3)
    {

        glm::vec3 & v0 = vertices[i+0];
        glm::vec3 & v1 = vertices[i+1];
        glm::vec3 & v2 = vertices[i+2];

        glm::vec2 & uv0 = uvs[i+0];
        glm::vec2 & uv1 = uvs[i+1];
        glm::vec2 & uv2 = uvs[i+2];

        glm::vec3 deltaPos1 = v1 - v0;
        glm::vec3 deltaPos2 = v2 - v0;

        glm::vec2 deltaUV1 = uv1 - uv0;
        glm::vec2 deltaUV2 = uv2 - uv0;

        float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
        glm::vec3 tangent = (deltaPos1 * deltaUV2.y   - deltaPos2 * deltaUV1.y)*r;
        glm::vec3 bitangent = (deltaPos2 * deltaUV1.x   - deltaPos1 * deltaUV2.x)*r;

        tangents.push_back(tangent);
        tangents.push_back(tangent);
        tangents.push_back(tangent);

        bittangents.push_back(bitangent);
        bittangents.push_back(bitangent);
        bittangents.push_back(bitangent);

    }

}

GLuint Mesh::vao() const {
    return mVAO;
}
