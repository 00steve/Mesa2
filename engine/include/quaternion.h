#ifndef UTIL_Quaternion
#define UTIL_Quaternion

#include <cmath>

class quaternion {
public:
    double x;
    double y;
    double z;
    double w;

    double magnitude();
    double* matrix();
    void normalize();
    quaternion operator * (const quaternion o);
    quaternion();
    quaternion(double w, double x, double y, double z);
    void rotateX(double angle);
    void rotateY(double angle);
    void rotateZ(double angle);
    /*pass two quaternions into the function and a t value between 0 and 1, 
    if the value is 0, the output will be equal to a, if it is 1, the output
    value will be equal to b. For any t between 0 and 1, the output will be
    an interpolation of quaternion a and quaternion b.*/
    static quaternion slerp(quaternion a, quaternion b, double t);
    static quaternion slerp(quaternion a, quaternion b, double min, double max, double t);
};

#endif