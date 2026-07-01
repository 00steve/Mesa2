#include "../../include/scene/fps.h"



FirstPersonShooter::FirstPersonShooter(){
    
    Viewport* viewport3d = new Viewport3d();
    AddChild(viewport3d);

    //setup camera
    Camera* cam1 = new Camera();
    //for some reason we see shit if the z index is positive and don't if it is negative
    cam1->SetPosition(double3(0,2,-14));
    cam1->SetTargetPosition(double3(0,0,0));
    cam1->SetMode(ManualKeyboardMouse2dMove);
    viewport3d->SetCamera(cam1);

    Cube* cube1 = new Cube(2);
    cube1->Name("my cube");
    viewport3d->AddChild(cube1);


    Cube* cube2 = new Cube(1);
    cube2->Name("cube 2");
    cube2->SetPosition(double3(2,0,0));
    viewport3d->AddChild(cube2);
}