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
        Color(float r, float g, float b, float a=1.0f);

        Color(const Color& c);
        Color& operator=(const Color& other);

        ~Color();

        float red() const;
        float green() const;
        float blue() const;
        float alpha() const;
        float gamma() const;

        // Returns a yellow color.
        static Color Yellow();
        static Color Pink();
        static Color LightGrey();
        static Color DarkGrey();
        static Color Red();
        static Color Green();
        static Color Blue();

   private:

        float mGamma;
        glm::vec4 mColorData;


    };

}

#endif // COLOR_H
