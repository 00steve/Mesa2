#ifndef UTIL_Cube
#define UTIL_Cube

#include "../double3.h"
#include "../physical.h"
#include "../timer.h"
#include "../displayable.h"
#include "../displayable/triangle.h"

class Cube : public Displayable, public Physical {
    
private:
    double3* colors;
    triangle* faces;
    double size;
    Timer timer;
    double3* vertices;

    void BuildFaces();
    void Init(const double size);

protected:
    void DrawThis();

public:
    static double3* BuildVertices(double size);
    Cube();
    Cube(double size);
    ~Cube();

};

#endif