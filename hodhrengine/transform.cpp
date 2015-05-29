#include "transform.h"
#include "debug.h"

// glm includes


#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_inverse.hpp>

using namespace Hodhr;

Transform::Transform()
    :   mScale(1,1,1),
        mPosition(0,0,0),
        mDirection(1,0,0),
        mRight(0,0,1),
        mUp(0,1,0)
{

}

Transform::~Transform()
{

}

void Transform::lookAt(const Transform & target, const glm::vec3& worldUp)
{
    mDirection = target.position() - this->position();
    // mDirection = this->position() - target.position();
    mDirection = glm::normalize(mDirection);
    mUp = worldUp;
    mRight = glm::cross(mDirection, mUp);
}

// rotates the camera about the 2D plane.
void Transform::rotate(float amount, float dx, float dy)
{

    mLocalEulerAngles[0] += amount * dx;
    mLocalEulerAngles[1] += amount * dy;

    mDirection = glm::vec3(
                cos(mLocalEulerAngles[1]) * sin(mLocalEulerAngles[0]),
                sin(mLocalEulerAngles[1]),
                cos(mLocalEulerAngles[1]) * cos(mLocalEulerAngles[0])
                );

    mRight = glm::vec3(sin(mLocalEulerAngles[0] - glm::pi<float>()/2.0f),
                      0,
                      cos(mLocalEulerAngles[0] - glm::pi<float>()/2.0f)
                      );

    mUp = glm::cross(mRight, mDirection);

}

void Transform::rotate(const glm::vec3 & eulerAngles, Space relativeTo )
{
    if (relativeTo == SPACE_SELF) {
        mRotation = glm::rotate(mRotation, eulerAngles[0], glm::vec3(1,0,0));
        mRotation = glm::rotate(mRotation, eulerAngles[1], glm::vec3(0,1,0));
        mRotation = glm::rotate(mRotation, eulerAngles[2], glm::vec3(0,0,1));
        mRotation = glm::normalize(mRotation);
    } else {


    }
}

void Transform::translate(float x, float y, float z)
{
    //Debug::addLog("translate", "test");

    const glm::vec3 t(x,y,z);

    mPosition += t;
}

Transform* Transform::root() const
{
    return mRoot;
}

glm::vec3 Transform::direction() const
{
    return mDirection;
}

glm::vec3 Transform::position() const
{
    return mPosition;
}

glm::vec3 Transform::up() const
{
    return mUp;
}

glm::quat Transform::rotation() const
{
    return mRotation;
}

glm::mat4 Transform::matrix() const
{
    const glm::mat4 t = glm::translate(
                glm::mat4(1.0f),
                mPosition
                );

    const glm::mat4 s = glm::scale(glm::mat4(1.0f), mScale);

    const glm::mat4 r = glm::toMat4(mRotation);

    return t*r*s;
}
