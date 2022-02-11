//
//  Camera.hpp
//  Engine
//

#ifndef Camera_hpp
#define Camera_hpp

#include <iostream>
#include "Types.hpp"
#include "Transform.hpp"

class Camera {
public:
    Transform transform;
    Matrix4f getViewMatrix();
};

#endif /* Camera_hpp */
