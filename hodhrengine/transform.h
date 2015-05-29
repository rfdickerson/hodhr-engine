#ifndef TRANSFORM_H
#define TRANSFORM_H

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"

namespace Hodhr {

typedef enum {
    SPACE_WORLD,
    SPACE_SELF
} Space;

class Transform
{
public:
    Transform();
    ~Transform();

    void translate(float x, float y, float z);
    void rotate(float amount, float dx, float dy);
    void rotate(const glm::vec3 & eulerAngles, Space relativeTo );

    void lookAt(const Transform & target, const glm::vec3 & worldUp);
    Transform* root() const;

    glm::vec3 direction() const;
    glm::vec3 position() const;
    glm::vec3 up() const;
    glm::quat rotation() const;
    glm::mat4 matrix() const;


protected:

    Transform *mRoot;

    glm::vec3 mScale;
    glm::vec3 mPosition;
    glm::vec3 mDirection;
    glm::vec3 mRight;
    glm::vec3 mUp;

    glm::vec3 mLocalEulerAngles;

    glm::quat mRotation;
};

}

#endif // TRANSFORM_H
