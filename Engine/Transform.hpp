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
        Vector3 a = glm::eulerAngles(rotation);
        return glm::normalize(Vector3(sin(a.y), sin(a.z), cos(a.y)));
    }
};

#endif /* Transform_hpp */
