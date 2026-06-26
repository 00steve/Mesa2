#ifndef DISPLAYABLE_TRIANGLEMESH_H
#define DISPLAYABLE_TRIANGLEMESH_H

#include "../double3.h"
#include "../displayable.h"
#include "triangle.h"

class triangleMesh : public Displayable {
private:
    unsigned int colorCount;
    double3* colors = NULL;
    unsigned int triangleCount;
    triangle* triangles = NULL;
    unsigned int vertexCount;
    double3* vertices = NULL;

    
public:
    void DrawThis();
    triangleMesh();
    triangleMesh(unsigned int colorCount, unsigned int vertexCount, unsigned int triangleCount);
    ~triangleMesh();
};


#endif