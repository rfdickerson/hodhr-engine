#pragma once

#include <glm/common.hpp>

#include "common.hpp"

namespace Hodhr {

/**
 * Vector3
 * Representation of 3D vectors and points.
 * This structure is used throughout to pass 3D positions and directions around.
 **/
class Vector3 {

public:

  Vector3(float x, float y, float z);
  ~Vector3();

  // Shorthand for writing Vector3(0,0,-1).
  static Vector3 back();
  // Shorthand for writing Vector3(0,-1,0).
  static Vector3 down();
  static Vector3 forward();
  
  static Vector3 left();
  
  static Vector3 one();
  
  static Vector3 right();

  static Vector3 up();
  
  static Vector3 zero();
  
  // returns the length of this vector.
  float magnitude();

  // returns this vector with a magnitude of 1.
  Vector3 normalized();

  // returns the squared length of this vector.
  float sqrMagnitude();

  float x();
  float y();
  float z();

  std::string toString();

  static float dot(const Vector3 & a, const Vector3 & b);
  static float distance(const Vector3 &a, const Vector3 &b);
  

protected:


  glm::vec3 _vector;

};

}
