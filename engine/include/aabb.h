#ifndef UTILS_AABB
#define UTILS_AABB

#include "double3.h"

class AABB {
private:
    double3 center;
    double3 halfSize;
    bool initialized = false;
    double length;
    double3 min;
    double3 max;
    double3 size;

    void Recalculate();

public:
    /**
     * Default constructor for an Axis Aligned Bounding Box (AABB). If the default 
     * constructor is used, it will be set to invalid.
    */
    AABB();
    AABB(double3 min, double3 max);
    AABB CalculateFromTwoPoints(double3 p1, double3 p2);
    double Depth();
    double3 Size();
    double3 HalfSize();
    double Height();
    /**
     * @brief If the bounding box actually has data and is valid. This value is 
     * updated whenever a new point is added using the UpdateBounds() function.
     * @return bool
    */
    bool IsValid();
    /*the multidimensional length of the AABB. This is basically
    the distance from the min to the max point.*/
    double Length();
    double3 LowerBounds();
    /*sets it so it doesn't assume there is any min or max. Basically the next 
    time a point is added, it will just use it as both the min and the max, since 
    it has no other data.*/
    void Reset();
    /*given a point in 3d space, check if the bounds should be grown or moved*/
    bool UpdateBounds(double3 point);
    double3 UpperBounds();
    double Width();

};


#endif