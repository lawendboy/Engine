//
//  Camera.cpp
//  Engine
//

#include "Camera.hpp"

Matrix4f Camera::getViewMatrix(){
    return glm::translate(glm::toMat4(Camera::transform.rotation), Camera::transform.position);
}
