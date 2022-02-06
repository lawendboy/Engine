//
//  Debug.hpp
//  Engine
//

#ifndef Debug_hpp
#define Debug_hpp

#include <iostream>

class Debug {
public:
    static void init();
    static void glInit();
    
    static void log(std::string message);
    static void error(std::string message);
    static void warn(std::string message);
    
    static void error(char message[]);
};

#endif
