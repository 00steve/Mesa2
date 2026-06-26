#ifndef GRIDFLOOR_H
#define GRIDFLOOR_H

#include "../displayable/triangleMesh.h"
#include "../physical.h"

class GridFloor : public Displayable, public Physical{
private:
    triangleMesh* mesh;



public:
    GridFloor();


};



#endif