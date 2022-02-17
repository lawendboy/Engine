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

void Shader::setMat4f(std::string name, glm::mat4 mat){
    glUniformMatrix4fv(glGetUniformLocation(Shader::shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMaterial(Material &material){
    glUniform3fv(glGetUniformLocation(Shader::shaderProgram, "material.ambient"), 1, &material.ambient[0]);
//    glUniform3fv(-1, 1, &material.ambient[0]);
    glUniform3fv(glGetUniformLocation(Shader::shaderProgram, "material.diffuse"), 1, &material.diffuse[0]);
//    glUniform3fv(-1, 1, &material.diffuse[0]);
    glUniform3fv(glGetUniformLocation(Shader::shaderProgram, "material.specular"), 1, &material.specular[0]);
//    glUniform3fv(-1, 1, &material.specular[0]);
    glUniform1f(glGetUniformLocation(Shader::shaderProgram, "material.shininess"), material.shininess);
//    glUniform1f(-1, material.shininess);
    glBindTexture(GL_TEXTURE_2D, material.texture.id);
}

void Shader::setVector3(std::string name, Vector3 &vec){
    glUniform3fv(glGetUniformLocation(Shader::shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::setInt(std::string name, int value){
    glUniform1i(glGetUniformLocation(Shader::shaderProgram, name.c_str()), value);
}
