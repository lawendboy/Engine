//
//  Debug.cpp
//  Engine
//

#include "Debug.hpp"
#include "coreGL.h"

void Debug::log(std::string message){
    std::cout << "Log: "<< message << '\n';
}

void Debug::warn(std::string message){
    std::cout << "Warning: " << message << '\n';
}

void Debug::error(std::string message){
    std::cout << "Error: " << message << '\n';
}

void Debug::error(char message[]){
    std::cout << "Error: " << message << '\n';
}

void Debug::init() {
    if(!glfwInit()){
        std::cerr << "ERROR, CANNOT INITIALIZE GLFW\n";
        return;
    }
}

void Debug::glInit() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        Debug::error("Cannot initialize glad");
    }
}
