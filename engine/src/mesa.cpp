#include "../include/mesa.h"

bool Mesa::AddChildThis(Node* newChild){
    /*if(dynamic_cast<Window*>(newChild)){
        windows.push_back(dynamic_cast<Window*>(newChild));
        AddDependency(newChild);
        return true;
    }*/
    if(dynamic_cast<Scene*>(newChild)){
        scenes.push(dynamic_cast<Scene*>(newChild));
        currentScene = dynamic_cast<Scene*>(newChild);
    }
    return Displayable::AddChildThis(newChild);
}


void Mesa::DrawThis(){
    if(currentScene){
        currentScene->Draw();
    }
}


Mesa::Mesa(){
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        exit(1);
    } 

    if( TTF_Init() < 0) {
        std::cout << "Error initializing SDL ttf font: " << TTF_GetError() << std::endl;
        exit(1);
    }

    window = new Window();
    AddChild(window);

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
    if(currentScene){
        currentScene->Update();
    }
    this->Draw();
}