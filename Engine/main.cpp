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
#include "Material.hpp"

int main() {
    
    Camera camera;
    
    Debug::init();

    Window window;
    window.FOV = 70;
    window.init();

    Mesh plane = ObjectLoader::loadMesh("/Users/ /Desktop/Engine/Models/plane.obj");
    Mesh cube = ObjectLoader::loadMesh("/Users/ /Desktop/Engine/Models/untitled.obj");
    
    Texture txt = TextureManager::createTexture("/Users/ /Desktop/Engine/Textures/test.jpeg", true);
    Texture planeTxt = TextureManager::createTexture("/Users/ /Desktop/Engine/Textures/wood.jpg", true);
    
    Shader shader;
    shader.create("/Users/ /Desktop/Engine/Shaders/vertex.glsl", "/Users/ /Desktop/Engine/Shaders/fragment.glsl");
    
    shader.use();
    
    glm::mat4 projection = window.getProjectionMatrix();
    
    shader.setMat4f("projection", projection);
    
    float pitch = 0.0f;
    float yaw = 0.0f;
    
    camera.transform.position.y = 5;
    
    window.setMultisampling(4);
    
    Vector3 lightPos1(-10.0f, 10.0f, 10.0f);
    Vector3 lightPos2(-10.0f, 10.0f, -10.0f);
    Vector3 lightPos3(10.0f, 10.0f, 10.0f);
    Vector3 lightPos4(10.0f, 10.0f, -10.0f);
    
    Vector3 lightCol1(10.0);
    Vector3 lightCol2(10.0);
    Vector3 lightCol3(10.0);
    Vector3 lightCol4(10.0);
    
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
        
        camera.transform.rotation = Quaternion(Vector3(pitch, yaw, 0.0f));
        shader.setMat4f("view", camera.getViewMatrix());
        shader.setVector3("viewPos", camera.transform.position);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader.setVector3("lightPositions[0]", lightPos1);
        shader.setVector3("lightPositions[1]", lightPos2);
        shader.setVector3("lightPositions[2]", lightPos3);
        shader.setVector3("lightPositions[3]", lightPos4);
        
        shader.setVector3("lightColors[0]", lightCol1);
        shader.setVector3("lightColors[1]", lightCol2);
        shader.setVector3("lightColors[2]", lightCol3);
        shader.setVector3("lightColors[3]", lightCol4);
        
        shader.setMat4f("model", glm::scale(Matrix4f(1.0f), Vector3(50.0f, 0.0f, 50.0f)));
        glBindVertexArray(plane.id);
        glBindTexture(GL_TEXTURE_2D, planeTxt.id);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        shader.setMat4f("model", glm::rotate(glm::translate(Matrix4f(1.0f), Vector3(0.0f, 5.0f, 0.0f)), (float)glfwGetTime() , glm::vec3(1.0f, 1.0f, 1.0f)));
        glBindVertexArray(cube.id);
        glBindTexture(GL_TEXTURE_2D, txt.id);
        glDrawArrays(GL_TRIANGLES, 0, cube.vertices);
        
        glfwPollEvents();
        window.swapBuffers();
    }
}
