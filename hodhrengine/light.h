#ifndef LIGHT_H
#define LIGHT_H

#include "behavior.h"
#include "color.h"

namespace Hodhr {


typedef enum {
    LIGHT_AUTO,
    LIGHT_FORCE_PIXEL,
    LIGHT_FORCE_VERTEX
} LightRenderMode;

class Light : public Behavior
{
public:
    Light(const GameObject& gameObject);
    ~Light();

    void setColor(Color color);



private:
    float mIntensity;
    Color mColor;
    LightRenderMode mRenderMode;
    float mShadowStrength;

};

}

#endif // LIGHT_H
