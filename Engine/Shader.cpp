//
//  Shader.cpp
//  Engine
//

#include "Shader.hpp"
#include "Debug.hpp"

void Shader::create(std::string vertexPath, std::string fragmentPath){
    std::ifstream vStream(vertexPath);
    std::string tempStr;
    std::string line;
    
    while (vStream >> line){
        tempStr += line;
        if(vStream.peek() == '\n')
            tempStr += "\n";
        if(vStream.peek() == ' ')
            tempStr += " ";
    }
    vStream.close();
    const char* vertexShaderCode = tempStr.c_str();
    
    std::ifstream fStream(fragmentPath);
    std::string scnTempStr;
    while (fStream >> line){
        scnTempStr += line;
        if(fStream.peek() == '\n')
            scnTempStr += "\n";
        if(fStream.peek() == ' ')
            scnTempStr += " ";
    }
    fStream.close();
    
    const char* fragmentShaderCode = scnTempStr.c_str();
    
    uint32_t vShader;
    vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vShader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vShader, 512, NULL, infoLog);
        Debug::error(infoLog);
    }
    
    uint32_t fShader;
    fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fShader);
    
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fShader, 512, NULL, infoLog);
        Debug::error(infoLog);
    }
    
    Shader::shaderProgram = glCreateProgram();
    glAttachShader(Shader::shaderProgram, vShader);
    glAttachShader(Shader::shaderProgram, fShader);
    glLinkProgram(Shader::shaderProgram);
    
    glGetProgramiv(Shader::shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(Shader::shaderProgram, 512, NULL, infoLog);
        Debug::error(infoLog);
    }
    
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::use() {
    glUseProgram(Shader::shaderProgram);
}

void Shader::setMat4f(char name[], glm::mat4 mat){
    glUniformMatrix4fv(glGetUniformLocation(Shader::shaderProgram, name), 1, GL_FALSE, glm::value_ptr(mat));
}
