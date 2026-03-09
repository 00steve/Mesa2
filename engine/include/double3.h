#ifndef UTIL_Double3
#define UTIL_Double3

#include <cmath>
#include <string> 
#include <random>

class double3{
public:
    union{
        double x;
        double r;
    };
    union{
        double y;
        double g;
    };
    union{
        double z;
        double b;
    };

    double3();
    double3(double x, double y, double z);
    double3 cross(double3 other);
    static double3 cross(double3 a, double3 b);
    double dot(double3 other);
    static double dot(double3 a, double3 b);
    /*All values should be between 0 and 1 for OpenGL goodness*/
    static double3 random(double rMin, double rMax, double gMin, double gMax, double bMin, double bMax);
    static double3 randomRGB();
    /*returns what this object is if it were normalized.*/
    double3 getNormalized();
    double length();
    /*I may be wrong, but I think if you have a function called 
    Normalize(), it should normalize the object, so that is what 
    this fucking thing does. If you just want the normalized 
    version of this object, called the "normalized()" function.*/
    double3 normalize();
    std::string toString();

    double operator [] (int index);
    double3 operator + (double3 other);
    double3 operator += (double3 other);
    double3 operator - (double3 other);
    double3 operator -= (double3 other);
    double3 operator * (double3 other);
    double3 operator / (double3 other);
    double3 operator + (double other);
    double3 operator += (double other);
    double3 operator * (double other);
    double3 operator / (double other);

};


#endif