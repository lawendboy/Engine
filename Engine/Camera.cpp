//
//  Camera.cpp
//  Engine
//

#include "Camera.hpp"

Matrix4f Camera::getViewMatrix(){
    Vector3 rot = glm::eulerAngles(Camera::transform.rotation);
    Matrix4f matrix = glm::translate(glm::rotate(glm::rotate(glm::rotate(glm::mat4(1.0f), rot.x, Vector3(1, 0, 0)), rot.y, Vector3(0, 1, 0)), rot.z, Vector3(0, 0, 1)), Camera::transform.position);
    return matrix;
}
