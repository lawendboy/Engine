//
//  Transform.hpp
//  Engine
//

#ifndef Transform_hpp
#define Transform_hpp

#include <iostream>
#include "Types.hpp"

class Transform {
public:
    Vector3 position;
    Quaternion rotation;
    Vector3 scale;
    Vector3 forward(){
        return Vector3(
                       2 * (Transform::rotation.x * Transform::rotation.z + Transform::rotation.w * Transform::rotation.y),
                       2 * (Transform::rotation.y * Transform::rotation.z - Transform::rotation.w * Transform::rotation.x),
                       - 1 + 2 * (Transform::rotation.x * Transform::rotation.x + Transform::rotation.y * Transform::rotation.y)
                       );
    }
    Vector3 left(){
        return Vector3(
                       - 1 + 2 * (Transform::rotation.y * Transform::rotation.y + Transform::rotation.z * Transform::rotation.z),
                       - 2 * (Transform::rotation.x * Transform::rotation.y + Transform::rotation.w * Transform::rotation.z),
                       2 * (Transform::rotation.x * Transform::rotation.z - Transform::rotation.w * Transform::rotation.y)
                       );
    }
    Vector3 up(){
        return Vector3(
                       - 2 * (Transform::rotation.x * Transform::rotation.y - Transform::rotation.w * Transform::rotation.z),
                       - 1 + 2 * (Transform::rotation.x * Transform::rotation.x + Transform::rotation.z * Transform::rotation.z),
                       2 * (Transform::rotation.y * Transform::rotation.z + Transform::rotation.w * Transform::rotation.x)
                       );
    }
};

#endif /* Transform_hpp */
