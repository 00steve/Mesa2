#ifndef UTIL_Positionable
#define UTIL_Positionable

#include "double3.h"
#include "aabb.h"
#include <iostream>

class Positionable{
private:
    /*Stores the total bounds of the positionable object. If the 
    OnSetPosition() function is never overridden, it will build an
    aabb that represents the movement of the point that represents 
    the positionable object. Hopefully this can be used to maybe 
    do collision on objects without any actual geometry? Maybe? I 
    guess we'll see, fuck face.*/
    AABB aabb;

    /*Represents where the positionable object is. This is a most 
    basic coordinate to check where an object is. It could probably
    be used to see if objects enter or leave areas, etc. Nothing 
    special, but probably very useful.*/
    double3 currentPosition;

    /*Store where the positionable object last was. This could 
    probably be used at some point to figure the velocity of the 
    object and use it to do some physics where there is a collision
    or some other things where velocity would be nice to know.
    Who knows? I'm a doctor too!*/
    double3 previousPosition;

protected:
    virtual void OnSetPosition();

public:
    AABB* GetAABB();
    double3 GetPosition();
    double3* PositionPtr();
    double3 GetPreviousPosition();
    double3* PreviousPositionPtr();
    Positionable();
    double3 SetPosition(double3 newPosition);

};

#endif