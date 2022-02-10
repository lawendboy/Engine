//
//  Shader.hpp
//  Engine
//

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
    void setMat4f(char name[], glm::mat4 mat);
};

#endif /* Shader_hpp */
