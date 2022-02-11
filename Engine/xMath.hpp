//
//  xMath.hpp
//  Engine
//

#ifndef xMath_hpp
#define xMath_hpp

#include <iostream>

class xMath {
public:
    static float Q_rsqrt(float num){
        const float threehalfs = 1.5f;
        float y = num;
        
        long i = * (long *) &y;
        
        i = 0x5f3759df - (i >> 1);
        y = * (float *) &i;
        
        y = y * ( threehalfs - ( (num * 0.5f) * y * y ));
        y = y * ( threehalfs - ( (num * 0.5f) * y * y ));
        
        return y;
    }
};

#endif /* xMath_hpp */
