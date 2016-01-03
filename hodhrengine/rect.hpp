#ifndef RECT_H
#define RECT_H

#include <glm/glm.hpp>

namespace Hodhr {


class Rect
{
public:
    Rect(float left, float top, float width, float height);
    ~Rect();

    glm::vec2 center;
    float height;

    /**
     * @brief Upper right corner of the rectangle.
     */
    glm::vec2 max;

    /**
     * @brief Lower left corner of the rectangle.
     */
    glm::vec2 min;

    /**
     * @brief The size of the rectangle.
     */
    glm::vec2 size;



};


}

#endif // RECT_H
