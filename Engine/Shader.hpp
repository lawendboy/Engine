//
//  Shader.hpp
//  Engine
//

#include "Material.hpp"

#ifndef Shader_hpp
#define Shader_hpp

#include "coreGL.h"
#include <iostream>
#include <fstream>

class Shader {
private:
    uint32_t shaderProgram;
public:
    void create(std::string vertexPath, std::string fragmentPath);
    void use();
    void setMat4f(std::string name, glm::mat4 mat);
    void setMaterial(Material &material);
    void setVector3(std::string name, Vector3 &vec);
    void setInt(std::string name, int value);
};

#endif /* Shader_hpp */
