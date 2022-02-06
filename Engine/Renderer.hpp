//
//  Renderer.hpp
//  Engine
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <iostream>
#include "Shader.hpp"

class Renderer {
private:
    Shader mainShader;
public:
    void init();
    void drawFrame();
};

#endif /* Renderer_hpp */
