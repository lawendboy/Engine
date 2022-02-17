//
//  Window.cpp
//  Engine
//

#include "Window.hpp"
#include "Debug.hpp"
#include "Texture.hpp"
#include "ObjectLoader.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

void frameBufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void Window::init() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
//    if(Window::WIDTH == 0)
        Window::WIDTH = 800;
//    if(Window::HEIGHT == 0)
        Window::HEIGHT = 600;
    Window::window = glfwCreateWindow(Window::WIDTH, Window::HEIGHT, Window::title, NULL, NULL);
    if(window == NULL)
        Debug::error("Cannot create window");
    
    glfwSetFramebufferSizeCallback(Window::window, frameBufferSizeCallback);
    
    glfwMakeContextCurrent(window);
    
    Debug::glInit();
    glEnable(GL_DEPTH_TEST);
#ifdef __APPLE__
    glViewport(0, 0, Window::WIDTH * 2, Window::HEIGHT * 2);
#else
    glViewport(0, 0, Window::WIDTH, Window::HEIGHT);
#endif
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

glm::mat4 Window::getProjectionMatrix(){
    return glm::perspective(glm::radians((float) Window::FOV), (float) Window::WIDTH / (float) Window::HEIGHT, 0.1f, 1000.0f);
}

bool Window::getWindowShouldClose(){
    return glfwWindowShouldClose(Window::window);
}

bool Window::getKey(uint32_t key){
    return glfwGetKey(Window::window, key);
}

void Window::setWindowClose(){
    glfwSetWindowShouldClose(Window::window, GLFW_TRUE);
}

void Window::swapBuffers(){
    glfwSwapBuffers(Window::window);
}

void Window::setMultisampling(uint32_t samples){
    glfwWindowHint(GLFW_SAMPLES, samples);
    if(samples == 1)
        glDisable(GL_MULTISAMPLE);
    else
        glEnable(GL_MULTISAMPLE);
}
