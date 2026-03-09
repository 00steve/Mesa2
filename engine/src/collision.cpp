#include "../include/collision.h"

Collision::Collision() : 
    intersection(false) 
        {
}

Collision::Collision(double3 newPoint){
    Point(newPoint);
}

bool Collision::Is(){
    return intersection;
}

double3 Collision::Point(){
    return point;
}

double3 Collision::Point(double3 newPoint)
{
    intersection = true;
    return point = newPoint;
}

AABB Collision::Volume(){
    return volume;
}

AABB Collision::Volume(AABB newVolume){
    intersection = true;
    return volume = newVolume;
}