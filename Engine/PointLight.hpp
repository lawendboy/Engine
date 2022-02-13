//
//  PointLight.hpp
//  Engine
//

#include "Types.hpp"

#ifndef PointLight_hpp
#define PointLight_hpp

class PointLight {
public:
    Vector3 position;
    
    float constant;
    float linear;
    float quadratic;
    
    Vector3 ambient;
    Vector3 diffuse;
    Vector3 specular;
};

#endif /* PointLight_hpp */
