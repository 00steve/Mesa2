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
    cam1->SetPosition(double3(-4,4,-4));
    cam1->SetTargetPosition(double3(0,0,0));
    viewport3d->SetCamera(cam1);

    Cube* cube1 = new Cube(2);
    cube1->Name("my cube");
    viewport3d->AddChild(cube1);

    this->Name("Mesa");
}

Mesa::~Mesa(){
    //delete loadingScreen;
    delete window;
    SDL_Quit();
}


bool Mesa::Quit(){
    return window->CloseWindow();
}


void Mesa::UpdateThis(){
    Timer::Update();
    this->Draw();
}