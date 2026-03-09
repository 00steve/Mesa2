#include "../include/mesa.h"


Mesa::Mesa(){
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        exit(1);
    } 
    window = new Window();
}

Mesa::~Mesa(){
    delete window;
    SDL_Quit();
}


bool Mesa::UpdateThis(){
    if(!window->Update()) return false;
    window->Draw();
    return true;
}