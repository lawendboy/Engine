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

#include "DirectionalLight.hpp"

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
    
    camera.transform.position.y = 5;
    
    Material material;
    material.ambient = Vector3(1.0f, 1.0f, 1.0f);
    material.diffuse = Vector3(1.0f, 1.0f, 1.0f);
    material.specular = Vector3(0.5f, 0.5f, 0.5f);
    material.shininess = 50.0f;
    material.texture = txt;
    
    Material planeMaterial;
    planeMaterial.ambient = Vector3(1.0f, 1.0f, 1.0f);
    planeMaterial.diffuse = Vector3(1.0f, 1.0f, 1.0f);
    planeMaterial.specular = Vector3(0.5f, 0.5f, 0.5f);
    planeMaterial.shininess = 50.0f;
    planeMaterial.texture = planeTxt;
    
    PointLight pointLight;
    pointLight.position = Vector3(0.0f, 60.0f, -10.0f);
    pointLight.ambient = Vector3(1.0f, 1.0f, 1.0f);
    pointLight.diffuse = Vector3(1.0f, 1.0f, 1.0f);
    pointLight.specular = Vector3(1.0f, 1.0f, 1.0f);
    pointLight.constant = 0.05f;
    pointLight.linear = 0.01f;
    pointLight.quadratic = 0.001f;
    
    shader.setPointLight(pointLight);
    
    DirectionalLight directionalLight;
    directionalLight.direction = Vector3(-0.2f, -1.0f, -0.3f);
    directionalLight.ambient = Vector3(0.15f, 0.15f, 0.15f);
    directionalLight.diffuse = Vector3(0.7f, 0.7f, 0.7f);
    directionalLight.specular = Vector3(1.0f, 0.5f, 1.0f);
    
    shader.setDirectionalLight(directionalLight);
    
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
        
        shader.setMaterial(material);
        model = glm::scale(model, Vector3(0.3f, 0.3f, 0.3f));
        model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime() , glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setMat4f("model", model);
        glBindVertexArray(mesh.id);
        glDrawArrays(GL_TRIANGLES, 0, mesh.vertices);
        
        shader.setMaterial(planeMaterial);
        model = glm::scale(Matrix4f(1.0f), Vector3(20.0f, 1.0f, 20.0f));
        shader.setMat4f("model", model);
        glBindVertexArray(plane.id);
        glDrawArrays(GL_TRIANGLES, 0, plane.vertices);
        
        glfwPollEvents();
        window.swapBuffers();
    }
}
