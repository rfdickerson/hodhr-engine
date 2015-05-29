#include "material.h"
#include "debug.h"

using namespace Hodhr;

Material::Material()
{
    mMaterialProperties = new MaterialPropertyBlock();
}

Material::~Material()
{
    delete mMaterialProperties;
}

void Material::setMatrix(const std::string name, const glm::mat4 mat)
{
    mMatrices[name] = mat;
}

Color Material::color() const
{
    return mColor;
}

MaterialPropertyBlock* Material::materialProperties() const
{
    return mMaterialProperties;
}

Shader* Material::shader() const
{
    return mShader;
}

void Material::setShader(Shader * shader)
{
    mShader = shader;
}

