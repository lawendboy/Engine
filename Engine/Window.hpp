//
//  Window.hpp
//  Engine
//

#ifndef Window_hpp
#define Window_hpp

#include <iostream>
#include "coreGL.h"

class Window {
private:
    GLFWwindow* window;
    uint16_t WIDTH;
    uint16_t HEIGHT;
    char title[];
public:
    void init();
};

#endif /* Window_hpp */
