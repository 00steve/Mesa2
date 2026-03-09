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
    
    viewport3d = new Viewport3d();
    window->AddChild(viewport3d);

    loadingScreen = new LoadingScreen();


    this->Name("Mesa");
}

Mesa::~Mesa(){
    delete loadingScreen;
    delete viewport3d;
    delete window;
    SDL_Quit();
}


bool Mesa::Quit(){
    return window->CloseWindow();
}


void Mesa::UpdateThis(){
    this->Draw();
}