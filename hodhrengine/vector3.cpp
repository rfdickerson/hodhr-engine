
#include "vector3.hpp"

#include <glm/common.hpp>
#include <glm/geometric.hpp>

using namespace Hodhr;

Vector3 Vector3::back() {
  return Vector3(0,0,-1);
}

Vector3 Vector3::down() {
  return Vector3(0,-1,0);
}

Vector3 Vector3::forward() {
  return Vector3(0,0,1);
}

Vector3 Vector3::up() {
  return Vector3(0,1,0);
}

Vector3 Vector3::zero() {
  return Vector3(0,0,0);
}

Vector3::Vector3(float x, float y, float z) {
    _vector = glm::vec3(x, y, z);
}

Vector3::~Vector3() {

}

float Vector3::magnitude() {
  return glm::length(this->_vector);
}

float Vector3::dot(const Vector3 &a, const Vector3 &b) {

  return glm::dot(a._vector, b._vector);

}

std::string Vector3::toString() {
  return std::string();
}
