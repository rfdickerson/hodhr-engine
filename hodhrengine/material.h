#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"
#include "texture.h"
#include "shader.h"
#include "materialpropertyblock.h"

namespace Hodhr {


/**
 * @brief The Material class
 *
 * This class exposes all properties from a material, allowing you to animate them. You can
 * also use it to set custom shader properties that can't be accessed through the inspector.
 */
class Material
{
public:
    Material();
    ~Material();

    void setShader(const std::string name, const Shader* shader);

    void setMatrix(const std::string name, const glm::mat4 mat);

    void setColor(const std::string name, const Color color);

    void setVector(const std::string name, const glm::vec4 vector);

    glm::vec4 getVector(const std::string name);

    void setMaterialPropertyBlock(MaterialPropertyBlock *materialPropertyBlock);

    void setShader(Shader * shader);

    // getters
    Color color() const;

    MaterialPropertyBlock* materialProperties() const;

    Shader* shader() const;


private:

    Color mColor;

    Texture * mMainTexture;

    MaterialPropertyBlock * mMaterialProperties;

    Shader * mShader;

    std::vector<std::string> mShaderKeywords;

    std::map<std::string, Color> mColors;

    std::map<std::string, glm::vec4> mVectors;

    std::map<std::string, glm::mat4> mMatrices;

};

}

#endif // MATERIAL_H
