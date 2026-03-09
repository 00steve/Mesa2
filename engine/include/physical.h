#ifndef UTIL_Physical
#define UTIL_Physical

#define EPSILON 0.000001

#include "node.h"
#include "positionable.h"
#include "collision.h"
#include "aabb.h"

class Physical : virtual public Node, public Positionable{
private:
    static double3 gravity;
protected:

public:
    static Collision AABBIntersection(AABB aabb0, AABB aabb1);
    static double3 Gravity();
    static double3 Gravity(double3 newGravity);
    Physical();
    static Collision TriangleLineSegmentIntersection(double3 l0, double3 l1, double3 t0, double3 t1, double3 t2);
    static Collision TriangleSphereIntersection(double3 p,double r,double3 t0,double3 t1,double3 t2);

};

#endif