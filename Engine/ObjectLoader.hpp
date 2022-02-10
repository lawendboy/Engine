//
//  ObjectLoader.hpp
//  Engine
//

#ifndef ObjectLoader_hpp
#define ObjectLoader_hpp

#include <iostream>
#include "Mesh.hpp"

class ObjectLoader {
public:
    static Mesh loadMesh(std::string filePath);
};

#endif /* ObjectLoader_hpp */
