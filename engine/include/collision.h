#ifndef UTILS_Collision
#define UTILS_Collision

#include "double3.h"
#include "aabb.h"

class Collision{
private:
    bool intersection;
    double3 point;
    AABB volume;

public:
    Collision();
    Collision(double3 newPoint);
    double3 Depth();
    bool Is();
    /*return the point of the intersection. If there is no intersection, 
    this value really doesn't mean anything, so have fun.*/
    double3 Point();
    /*Set a point at which the collision happened. When a point is set, it 
    also sets intersection to true, because you can't have an intersection 
    point without it being an intersection you daft fuck.*/
    double3 Point(double3 newPoint);
    AABB Volume();
    AABB Volume(AABB newVolume);
    /*apparently this lets you check if an intersection (collision) actually
    happened by just using the entire object as a boolean. We'll see about 
    that.*/
    explicit operator bool() const { 
        return intersection; 
    }

};





#endif