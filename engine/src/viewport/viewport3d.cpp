#include "../../include/viewport/viewport3d.h"


void Viewport3d::DrawThis(){
    Viewport::DrawThis();
}


void Viewport3d::UpdateThis(){
    //y = std::sin(LocalElapsedTime()*2)*7;
    //SetCameraTarget(double3(0,0,0));
    //SetCameraPosition(double3(0,y,10));
}

Viewport3d::Viewport3d(){
    Name("Viewport3d");
}

Viewport3d::~Viewport3d(){
}