#include "../include/mesa.h"


bool Mesa::AddChildThis(Node* newChild){
    /*if(dynamic_cast<Window*>(newChild)){
        windows.push_back(dynamic_cast<Window*>(newChild));
        AddDependency(newChild);
        return true;
    }*/
    return Displayable::AddChildThis(newChild);
}


void Mesa::DrawThis(){
    //std::cout << "draw mesa\n";
}


Mesa::Mesa(){
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        exit(1);
    } 


    window = new Window();
    AddChild(window);
    
    Viewport* viewport3d = new Viewport3d();
    window->AddChild(viewport3d);


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






    this->Name("Mesa");
}

Mesa::~Mesa(){
    SDL_Quit();
}


bool Mesa::Quit(){
    return window->CloseWindow();
}


void Mesa::UpdateThis(){
    Timer::Update();
    this->Draw();
}