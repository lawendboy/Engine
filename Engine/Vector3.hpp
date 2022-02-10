//
//  Vector3.hpp
//  Engine
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <iostream>

class Vector3 {
public:
    float x;
    float y;
    float z;
    Vector3 normalize(){
        float scl = std::sqrt(x * x + y * y + z * z);
        return Vector3{x / scl, y / scl, z / scl};
    }
    static Vector3 add(Vector3 vec, Vector3 vec2){
        return Vector3{vec.x + vec2.x, vec.y + vec2.y, vec.z + vec2.z};
    }
    static Vector3 scale(Vector3 vec, float scalar){
        return Vector3{vec.x * scalar, vec.y * scalar, vec.z * scalar};
    }
};

#endif /* Vector3_hpp */
