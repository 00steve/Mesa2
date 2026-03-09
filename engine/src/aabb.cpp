#include "../include/aabb.h"

AABB::AABB(){
}

AABB::AABB(double3 min, double3 max) : 
    min(min),
    max(max) 
        {
    UpdateBounds(min);
    UpdateBounds(max);
}

AABB AABB::CalculateFromTwoPoints(double3 p1, double3 p2){
    double3 min;
    double3 max;
    if(p1.x < p2.x){ min.x = p1.x; max.x = p2.x; } else { min.x = p2.x; max.x = p1.x; }
    if(p1.y < p2.y){ min.y = p1.y; max.y = p2.y; } else { min.y = p2.y; max.y = p1.y; }
    if(p1.z < p2.z){ min.z = p1.z; max.z = p2.z; } else { min.z = p2.z; max.z = p1.z; }
    return AABB(min,max);
}

double AABB::Depth(){
    return size.z;
}

double3 AABB::Size(){
    return size;
}

double3 AABB::HalfSize(){
    return halfSize;
}

double AABB::Height(){
    return size.y;
}

bool AABB::IsValid(){
    return initialized;
}

double AABB::Length(){
    return length;
}

double3 AABB::LowerBounds(){
    return min;
}

void AABB::Recalculate(){
    center = (max + min) * .5;
    size = max - min;
    halfSize = size * .5;
    length = size.length();
}

void AABB::Reset(){
    initialized = false;
}

bool AABB::UpdateBounds(double3 point){
    if(!initialized){
        min = max = point;
        return initialized = true;
    }
    bool changed = false;
    if(point.x < min.x){
        min.x = point.x;
        changed = true;
    } else if(point.x > max.x){
        max.x = point.x;
        changed = true;
    }
    if(point.y < min.y){
        min.y = point.y;
        changed = true;
    } else if(point.y > max.y){
        max.y = point.y;
        changed = true;
    }
    if(point.z < min.z){
        min.z = point.z;
        changed = true;
    } else if(point.z > max.z){
        max.z = point.z;
        changed = true;
    }
    if(changed){
        Recalculate();
    }
    return changed;
}

double3 AABB::UpperBounds(){
    return max;
}

double AABB::Width(){
    return size.x;
}