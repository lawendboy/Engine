//
//  Mat4.hpp
//  Engine
//

#ifndef Mat4_hpp
#define Mat4_hpp

#include <iostream>
#include "Vector3.hpp"

class Mat4 {
public:
    float val[16];
    Mat4(float a){
        val[0] = a;
        val[1] = 0.f;
        val[2] = 0.f;
        val[3] = 0.f;
        val[4] = 0.f;
        val[5] = a;
        val[6] = 0.f;
        val[7] = 0.f;
        val[8] = 0.f;
        val[9] = 0.f;
        val[10] = a;
        val[11] = 0.f;
        val[12] = 0.f;
        val[13] = 0.f;
        val[14] = 0.f;
        val[15] = a;
    }
    Mat4(Mat4 const &a){
        val[0] = a.val[0];
        val[1] = a.val[1];
        val[2] = a.val[2];
        val[3] = a.val[3];
        val[4] = a.val[4];
        val[5] = a.val[5];
        val[6] = a.val[6];
        val[7] = a.val[7];
        val[8] = a.val[8];
        val[9] = a.val[9];
        val[10] = a.val[10];
        val[11] = a.val[11];
        val[12] = a.val[12];
        val[13] = a.val[13];
        val[14] = a.val[14];
        val[15] = a.val[15];
    }
    float *prtValue(){
        return val;
    }
    static Mat4 transform(Mat4 mat, Vector3 vec){
        Mat4 result(mat);
        result.val[3] = result.val[0] * vec.x + result.val[1] * vec.x + result.val[2] * vec.x + result.val[3];
        result.val[7] = result.val[4] * vec.x + result.val[5] * vec.x + result.val[6] * vec.x + result.val[7];
        result.val[11] = result.val[8] * vec.x + result.val[9] * vec.x + result.val[10] * vec.x + result.val[11];
        result.val[15] = result.val[12] * vec.x + result.val[13] * vec.x + result.val[14] * vec.x + result.val[15];
        return result;
    }
};

#endif /* Mat4_hpp */
