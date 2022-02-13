//
//  DirectionalLight.hpp
//  Engine
//

#include "Types.hpp"

#ifndef DirectionalLight_hpp
#define DirectionalLight_hpp

class DirectionalLight {
public:
    Vector3 direction;
    Vector3 ambient;
    Vector3 diffuse;
    Vector3 specular;
};

#endif /* DirectionalLight_hpp */
