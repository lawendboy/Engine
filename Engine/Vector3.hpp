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
};

#endif /* Vector3_hpp */
