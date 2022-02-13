//
//  Material.hpp
//  Engine
//

#include "Types.hpp"
#include "Texture.hpp"

#ifndef Material_hpp
#define Material_hpp

class Material{
public:
    Texture texture;
    Vector3 ambient;
    Vector3 diffuse;
    Vector3 specular;
    float shininess;
};

#endif /* Material_hpp */
