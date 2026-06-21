#ifndef UTIL_float3
#define UTIL_float3

#include <cmath>
#include <string> 
#include <random>

class float3{
public:
    union{
        float x;
        float r;
    };
    union{
        float y;
        float g;
    };
    union{
        float z;
        float b;
    };

    float3();
    float3(float x, float y, float z);
    float3 cross(float3 other);
    static float3 cross(float3 a, float3 b);
    float dot(float3 other);
    static float dot(float3 a, float3 b);
    /*All values should be between 0 and 1 for OpenGL goodness*/
    static float3 random(float rMin, float rMax, float gMin, float gMax, float bMin, float bMax);
    static float3 randomRGB();
    /*returns what this object is if it were normalized.*/
    float3 getNormalized();
    float length();
    /*I may be wrong, but I think if you have a function called 
    Normalize(), it should normalize the object, so that is what 
    this fucking thing does. If you just want the normalized 
    version of this object, called the "normalized()" function.*/
    float3 normalize();
    std::string toString();

    float operator [] (int index);
    float3 operator + (float3 other);
    float3 operator += (float3 other);
    float3 operator - (float3 other);
    float3 operator -= (float3 other);
    float3 operator * (float3 other);
    float3 operator / (float3 other);
    float3 operator + (float other);
    float3 operator += (float other);
    float3 operator * (float other);
    float3 operator / (float other);

};


#endif