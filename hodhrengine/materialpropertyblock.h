#ifndef MATERIALPROPERTYBLOCK_H
#define MATERIALPROPERTYBLOCK_H

#include "color.h"
#include "texture.h"

#include <glm/glm.hpp>
#include <string>

namespace Hodhr {

/**
     * @brief A block of material values to apply.
     *
     * MaterialPropertyBlock is used by Graphics.DrawMesh and Renderer.SetPropertyBlock.
     * Use it in situations where you want to draw multiple objects with the same material,
     * but slightly different properties. For example, if you want to slightly change the color
     * of each mesh drawn.
     */
    class MaterialPropertyBlock
    {
    public:
        MaterialPropertyBlock();
        ~MaterialPropertyBlock();

        void addColor(std::string name, Color value);
        void addFloat(std::string name, float value);
        void addTexture(std::string name, Texture *value);
        void addVector(std::string name, glm::vec4 value);
        void addMatrix(std::string name, glm::mat4 value);

        void clear();

        glm::vec4 getVector(std::string name);

    };

}

#endif // MATERIALPROPERTYBLOCK_H
