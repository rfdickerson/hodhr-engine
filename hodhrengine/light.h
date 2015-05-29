#ifndef LIGHT_H
#define LIGHT_H

#include "behavior.h"
#include "color.h"

namespace Hodhr {

class Light : public Behavior
{
public:

    typedef enum {
        LIGHT_AUTO,
        LIGHT_FORCE_PIXEL,
        LIGHT_FORCE_VERTEX
    } LightRenderMode;

    typedef enum {
        LIGHT_SPOT,
        LIGHT_DIRECTIONAL,
        LIGHT_POINT,
        LIGHT_AREA
    } LightType;

    typedef enum {
        LIGHT_SHADOWS_NONE,
        LIGHT_SHADOWS_HARD,
        LIGHT_SHADOWS_SOFT
    } LightShadows;

    Light(const GameObject& gameObject);
    ~Light();

    Color color() const;
    void setColor(Color color);

    float intensity() const;
    float shadowStrength() const;
    float range() const;
    LightType lightType() const;
    LightShadows lightShadows() const;
    LightRenderMode renderMode() const;


private:
    float mIntensity;
    Color mColor;
    LightRenderMode mRenderMode;
    float mShadowStrength;
    float mRange;
    LightType mLightType;
    LightShadows mLightShadows;

};

}

#endif // LIGHT_H
