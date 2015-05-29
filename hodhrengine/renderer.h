#ifndef RENDERER_H
#define RENDERER_H

//#include "material.h"
#include "component.h"


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

    /**
     * @brief Makes the rendered 3D object visible if enabled.
     */
    bool enabled;

    /**
     * @brief Returns the first instantiated Material assigned to the renderer.
     */
    Material *material;

    ShadowCastingMode shadowCastingMode;

    /**
     * @brief Does this object receive shadows?
     */
    bool receiveShadows;

    glm::mat4 worldToLocalMatrix;


};

}

#endif // RENDERER_H
