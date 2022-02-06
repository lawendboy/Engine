//
//  main.cpp
//  Engine
//

#include <iostream>
#include "Shader.hpp"
#include "Window.hpp"
#include "Debug.hpp"
#include "Renderer.hpp"

int main() {
    Debug::init();
    
    Window window;
    window.init();
    
    Renderer renderer;
    renderer.init();
    
}
