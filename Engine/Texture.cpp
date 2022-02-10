//
//  Texture.cpp
//  Engine
//

#include "Texture.hpp"
#include "Debug.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture TextureManager::createTexture(std::string filePath) {
    uint32_t tmpId;
    glGenTextures(1, &tmpId);
    glBindTexture(GL_TEXTURE_2D, tmpId);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        Debug::error("Cannot create texture!");
    }
    
    stbi_image_free(data);
    
    return Texture{tmpId};
}

/* Na przyszłość:
 Usuwanie,
    unsigned int tex[] = {tex1, tex2, ..., texN};
    glDeleteTextures(N, tex);
 */
