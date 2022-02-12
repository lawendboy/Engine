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

    Mesh mesh = ObjectLoader::loadMesh("/Users/ /Desktop/Engine/Models/sus.obj");
    Mesh plane = ObjectLoader::loadMesh("/Users/ /Desktop/Engine/Models/plane.obj");
    
    Texture txt = TextureManager::createTexture("/Users/ /Desktop/Engine/Textures/test.jpeg");
    Texture planeTxt = TextureManager::createTexture("/Users/ /Desktop/Engine/Textures/block.jpg");
    
    Shader shader;
    shader.create("/Users/ /Desktop/Engine/Shaders/vertex.glsl", "/Users/ /Desktop/Engine/Shaders/fragment.glsl");
    
    shader.use();
    
    glm::mat4 projection = window.getProjectionMatrix();
    
    glm::mat4 model(1.0f);
    
    shader.setMat4f("projection", projection);
    
    float pitch = 0.0f;
    float yaw = 0.0f;
    
    while(!window.getWindowShouldClose()){
        if(window.getKey(GLFW_KEY_ESCAPE))
            window.setWindowClose();
        
        if(window.getKey(GLFW_KEY_W))
            camera.transform.position += camera.transform.forward() * 0.4f;
        if(window.getKey(GLFW_KEY_S))
            camera.transform.position -= camera.transform.forward() * 0.4f;
        
        if(window.getKey(GLFW_KEY_A))
            camera.transform.position += camera.transform.left() * 0.4f;
        if(window.getKey(GLFW_KEY_D))
            camera.transform.position -= camera.transform.left() * 0.4f;
        
        if(window.getKey(GLFW_KEY_Q))
            camera.transform.position += camera.transform.up() * 0.4f;
        if(window.getKey(GLFW_KEY_E))
            camera.transform.position -= camera.transform.up() * 0.4f;
        
        if(window.getKey(GLFW_KEY_LEFT))
            yaw -= 0.1f;
        if(window.getKey(GLFW_KEY_RIGHT))
            yaw += 0.1f;
        
        if(window.getKey(GLFW_KEY_UP))
            pitch -= 0.1f;
        if(window.getKey(GLFW_KEY_DOWN))
            pitch += 0.1f;
        
        camera.transform.rotation = glm::quat(Vector3(pitch, yaw, 0.0f));
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader.setMat4f("view", camera.getViewMatrix());
        
        glBindTexture(GL_TEXTURE_2D, txt.id);
        model = glm::scale(model, Vector3(0.3f, 0.3f, 0.3f));
        model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime() , glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setMat4f("model", model);
        glBindVertexArray(mesh.id);
        glDrawArrays(GL_TRIANGLES, 0, mesh.vertices);
        
        glBindTexture(GL_TEXTURE_2D, planeTxt.id);
        model = glm::scale(Matrix4f(1.0f), Vector3(20.0f, 1.0f, 20.0f));
        shader.setMat4f("model", model);
        glBindVertexArray(plane.id);
        glDrawArrays(GL_TRIANGLES, 9, plane.vertices);
        
        glfwPollEvents();
        window.swapBuffers();
    }
    
}
