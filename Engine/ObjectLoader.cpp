//
//  ObjectLoader.cpp
//  Engine
//

#include "ObjectLoader.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include "coreGL.h"

Mesh ObjectLoader::loadMesh(std::string filePath){
    std::ifstream stream(filePath);
    if(!stream){
        std::cout << "Cannot open file: " << filePath << std::endl;
    }
    std::string line;
    std::string ssLine;
    std::vector<float> pos;
    std::vector<float> normal;
    std::vector<float> tex;
    std::vector<float> output;
    std::vector<int> faces;
    std::vector<unsigned char> dataOutput;
    std::stringstream ss;
    
    while(stream >> line){
        if(line == "v"){
//            std::cout << "vertex pos\n";
            stream >> line;
            pos.push_back(std::stof(line));
            stream >> line;
            pos.push_back(std::stof(line));
            stream >> line;
            pos.push_back(std::stof(line));
        }else if(line == "vn"){
//            std::cout << "normals\n";
            stream >> line;
            normal.push_back(std::stof(line));
            stream >> line;
            normal.push_back(std::stof(line));
            stream >> line;
            normal.push_back(std::stof(line));
        }else if(line == "vt"){
//            std::cout << "textures\n";
            stream >> line;
            tex.push_back(std::stof(line));
            stream >> line;
            tex.push_back(std::stof(line));
        }else if(line == "f"){
            stream >> line;
            std::replace(line.begin(), line.end(), '/', ' ');
            ss.str(line);
            while(ss >> ssLine){
                faces.push_back(std::stoi(ssLine));
            }
            ss.str("");
            ss.clear();
            stream >> line;
            std::replace(line.begin(), line.end(), '/', ' ');
            ss.str(line);
            while(ss >> ssLine){
                faces.push_back(std::stoi(ssLine));
            }
            ss.str("");
            ss.clear();
            stream >> line;
            std::replace(line.begin(), line.end(), '/', ' ');
            ss.str(line);
            while(ss >> ssLine){
                faces.push_back(std::stoi(ssLine));
            }
            ss.str("");
            ss.clear();
        }else{
//            std::cout << "Other: " << line << '\n';
            continue;
        }
    }
    
    for(size_t i = 0; i < faces.size() / 3; i++){
        output.push_back(pos[(faces[3 * i] - 1) * 3]);
        output.push_back(pos[(faces[3 * i] - 1) * 3 + 1]);
        output.push_back(pos[(faces[3 * i] - 1) * 3 + 2]);
        
        output.push_back(tex[(faces[3 * i + 1] - 1) * 2]);
        output.push_back(tex[(faces[3 * i + 1] - 1) * 2 + 1]);
        
        output.push_back(normal[(faces[3 * i + 2] - 1) * 3]);
        output.push_back(normal[(faces[3 * i + 2] - 1) * 3 + 1]);
        output.push_back(normal[(faces[3 * i + 2] - 1) * 3 + 2]);
    }
    
    float arrOutput[output.size()];
    
    for(size_t i = 0; i < output.size(); i++){
        arrOutput[i] = output[i];
    }
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(arrOutput), arrOutput, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(1);
    uint32_t sz = output.size() / 8;
    Mesh mesh{VAO, sz ,VBO};
    return mesh;
}
