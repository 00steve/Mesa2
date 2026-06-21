#ifndef UTIL_Triangle
#define UTIL_Triangle

#include "../double3.h"
#include "../displayable.h"

class triangle : public Displayable {
public:
    double3** colors = NULL;
    /*create a static array that holds 3 double3 pointers.
    This way vertices can be shared between triangles.*/
    double3** vertices = NULL;

    void AssignColors(double3* c0, double3* c1, double3* c2);
    void AssignVertices(double3* v0, double3* v1, double3* v2);

    void DrawThis();
    void Init(double3* v0, double3* v1, double3* v2, double3* c0, double3* c1, double3* c2);
    triangle(double3* v0, double3* v1, double3* v2);
    triangle(double3* v0, double3* v1, double3* v2, double3* c0, double3* c1, double3* c2);
    ~triangle();
};

#endif