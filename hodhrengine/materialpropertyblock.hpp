#ifndef MATERIALPROPERTYBLOCK_H
#define MATERIALPROPERTYBLOCK_H

#include "color.hpp"
#include "texture.hpp"

#include <glm/glm.hpp>
#include <string>
#include <map>

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
        void addColor(int nameID, Color value);

        void addFloat(std::string name, float value);
        void addFloat(int nameID, float value);

        void addMatrix(std::string name, glm::mat4 value);
        void addMatrix(int nameID, glm::mat4 value);

        void addTexture(std::string name, const Texture * value);
        void addTexture(int nameID, const Texture * value);

        void addVector(std::string name, glm::vec4 value);
        void addVector(int nameID, glm::vec4 value);

        Color getColor(std::string name, Color value) const;
        Color getColor(int nameID, Color value) const;

        float getFloat(std::string name, float value) const;
        float getFloat(int nameID, float value) const;

        glm::mat4 getMatrix(std::string name, glm::mat4 value) const;
        glm::mat4 getMatrix(int nameID, glm::mat4 value) const;

        Texture getTexture(std::string name, const Texture * value) const;
        Texture getTexture(int nameID, const Texture * value) const;

        glm::vec4 getVector(std::string name, glm::vec4 value) const;
        glm::vec4 getVector(int nameID, glm::vec4 value) const;

        void clear();




    private:


    };

}

#endif // MATERIALPROPERTYBLOCK_H
