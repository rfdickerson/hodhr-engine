#include "material.h"
#include "debug.h"

using namespace Hodhr;

Material::Material()
    : mMainTexture(NULL)
{
    mMaterialProperties = new MaterialPropertyBlock();
}

Material::~Material()
{
    delete mMaterialProperties;
}

void Material::setMainTexture( Texture2D *texture)
{
    mMainTexture = texture;
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

Texture2D * Material::mainTexture() const
{
    return mMainTexture;
}

