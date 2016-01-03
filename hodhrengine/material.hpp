#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.hpp"
#include "texture.hpp"
#include "texture2d.hpp"
#include "shader.hpp"
#include "materialpropertyblock.hpp"

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

    void setMainTexture( Texture2D * texture);

    Texture2D * mainTexture() const;

    void setShader(const std::string name, const Shader* shader);

    void setMatrix(const std::string name, const glm::mat4 mat);

    void setColor(const std::string name, const Color color);

    void setVector(const std::string name, const glm::vec4 vector);

    glm::vec4 getVector(const std::string name);

    void setMaterialPropertyBlock(MaterialPropertyBlock *materialPropertyBlock);

    void setInt(const std::string name, int value);

    void setPass(int pass);

    void setShader(Shader * shader);

    void setTexture(const std::string propertyName, Texture * texture);

    Texture * getTexture(const std::string propertyName) const;

    // getters
    Color color() const;

    MaterialPropertyBlock* materialProperties() const;

    Shader* shader() const;


private:

    Color mColor;

    Texture2D * mMainTexture;

    MaterialPropertyBlock * mMaterialProperties;

    Shader * mShader;

    std::vector<std::string> mShaderKeywords;

    std::map<std::string, Color> mColors;

    std::map<std::string, glm::vec4> mVectors;

    std::map<std::string, glm::mat4> mMatrices;

    std::map<std::string, Texture *> m_textures;

};

}

#endif // MATERIAL_H
