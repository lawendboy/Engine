//
//  Window.cpp
//  Engine
//

#include "Window.hpp"
#include "Debug.hpp"

void frameBufferSizeCallback(GLFWwindow* window, int width, int height){
}

void Window::init() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    if(Window::WIDTH == 0)
        Window::WIDTH = 800;
    if(Window::HEIGHT == 0)
        Window::HEIGHT = 600;
    Window::window = glfwCreateWindow(Window::WIDTH, Window::HEIGHT, Window::title, NULL, NULL);
    if(window == NULL)
        Debug::error("Cannot create window");
    
    glfwSetFramebufferSizeCallback(Window::window, frameBufferSizeCallback);
    
    glfwMakeContextCurrent(window);
    
    Debug::glInit();
    
#ifdef __APPLE__
    glViewport(0, 0, Window::WIDTH * 2, Window::HEIGHT * 2);
#else
    glViewport(0, 0, Window::WIDTH, Window::HEIGHT);
#endif
}
