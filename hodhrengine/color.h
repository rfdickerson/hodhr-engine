#ifndef COLOR_H
#define COLOR_H

#define GLEW_STATIC
#include "GL/glew.h"
#include "glm/glm.hpp"

namespace Hodhr {

    class Color
    {
    public:
        Color();
        Color(float r, float g, float b, float a);

        Color(const Color& c);
        Color& operator=(const Color& other);

        ~Color();

        float getRed() const;
        float getGreen() const;
        float getBlue() const;
        float getAlpha() const;

        // Returns a yellow color.
        static Color yellow();
        static Color pink();
        static Color lightGrey();
        static Color darkGrey();
        static Color red();
        static Color green();
        static Color blue();

        float gamma;
        glm::vec4 colorData;


    };

}

#endif // COLOR_H
