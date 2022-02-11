//
//  main.cpp
//  Engine
//

#include <iostream>
#include "coreGL.h"

#include "Shader.hpp"
#include "Window.hpp"
#include "Debug.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"
#include "ObjectLoader.hpp"
#include "Types.hpp"
#include "Camera.hpp"

int main() {
    
    Camera camera;
    
    Debug::init();

    Window window;
    window.FOV = 70;
    window.init();

    Mesh mesh = ObjectLoader::loadMesh("/Users/Desktop/Engine/Models/sus.obj");
    
    Texture txt = TextureManager::createTexture("/Users/Desktop/Engine/Textures/test.jpeg");
    
    Shader shader;
    shader.create("/Users/Desktop/Engine/Shaders/vertex.glsl", "/Users/Desktop/Engine/Shaders/fragment.glsl");
    
    shader.use();
    
    glm::mat4 projection = window.getProjectionMatrix();
    
    glm::mat4 model(1.0f);
    
    shader.setMat4f("projection", projection);
    shader.setMat4f("model", model);
    
    float rotY = 0.0f;
    
    while(!window.getWindowShouldClose()){
        if(window.getKey(GLFW_KEY_ESCAPE))
            window.setWindowClose();
        
        if(window.getKey(GLFW_KEY_W))
            camera.transform.position += camera.transform.forward() * 0.4f;
        if(window.getKey(GLFW_KEY_S))
            camera.transform.position -= camera.transform.forward() * 0.4f;
        
        if(window.getKey(GLFW_KEY_A))
            camera.transform.position.x += 0.4f;
        if(window.getKey(GLFW_KEY_D))
            camera.transform.position.x -= 0.4f;
        
        if(window.getKey(GLFW_KEY_Q))
            camera.transform.position.y += 0.4f;
        if(window.getKey(GLFW_KEY_E))
            camera.transform.position.y -= 0.4f;
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader.setMat4f("view", camera.getViewMatrix());
        
        glBindTexture(GL_TEXTURE_2D, txt.id);
        
        model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime() , glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setMat4f("model", model);
        
        glBindVertexArray(mesh.id);
        glDrawArrays(GL_TRIANGLES, 0, mesh.vertices);
        
        glfwPollEvents();
        window.swapBuffers();
    }
    
}
