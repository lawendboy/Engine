//
//  Texture.hpp
//  Engine
//

#ifndef Texture_hpp
#define Texture_hpp

#include <iostream>
#include "coreGL.h"

class Texture {
public:
    uint32_t id;
};

class TextureManager {
public:
    static Texture createTexture(std::string filePath, bool gammaCorrection);
};

#endif /* Texture_hpp */
