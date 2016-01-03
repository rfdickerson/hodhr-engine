#ifndef RENDERER_H
#define RENDERER_H

//#include "material.h"
#include "component.hpp"


namespace Hodhr {

    class Material;
    class MaterialPropertyBlock;

/**
  * How shadows are cast from this object.
  *
*/
typedef enum {
    SHADOWS_OFF,
    SHADOWS_ON,
    SHADOWS_TWOSIDED,
    SHADOWS_SHADOWSONLY
} ShadowCastingMode;

class Renderer : public Component
{
public:
    Renderer(const GameObject &gameObject);
    ~Renderer();

    void onBecameInvisible();

    void onBecameVisible();

    MaterialPropertyBlock& getPropertyBlock() const;
    void setPropertyBlock(const MaterialPropertyBlock& propertyBlock);

    // get the current material
    Material * material() const;
    void setMaterial(Material *);

    bool enabled() const;
    void setEnabled(bool);

protected:


    bool mEnabled;

    Material * mMaterial;

    ShadowCastingMode shadowCastingMode;

    bool receiveShadows;

    glm::mat4 worldToLocalMatrix;


};

}

#endif // RENDERER_H
