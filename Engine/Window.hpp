//
//  Window.hpp
//  Engine
//

#ifndef Window_hpp
#define Window_hpp

#include <iostream>
#include "coreGL.h"

class Window {
public:
    uint32_t FOV;
    void init();
    void test();
    GLFWwindow* getWindow();
    glm::mat4 getProjectionMatrix();
    bool getWindowShouldClose();
    bool getKey(uint32_t key);
    void setWindowClose();
    void swapBuffers();
private:
    GLFWwindow* window;
    uint16_t WIDTH;
    uint16_t HEIGHT;
    char title[];
};

#endif /* Window_hpp */
