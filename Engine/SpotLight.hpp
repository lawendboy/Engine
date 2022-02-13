//
//  SpotLight.hpp
//  Engine
//

#include "Types.hpp"

#ifndef SpotLight_hpp
#define SpotLight_hpp

class SpotLight {
public:
    Vector3 position;
    Vector3 direction;
    Vector3 ambient;
    Vector3 diffuse;
    Vector3 specular;
    float constant;
    float linear;
    float quadratic;
    float cutOff;
    float outerCutOff;
};

#endif /* SpotLight_hpp */
