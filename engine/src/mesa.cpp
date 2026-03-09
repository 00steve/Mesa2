#include "../include/mesa.h"


Mesa::Mesa(){
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        exit(1);
    } 
    window = new Window();
    loadingScreen = new LoadingScreen();
    viewport2d = new Viewport2d();
}

Mesa::~Mesa(){
    delete viewport2d;
    delete loadingScreen;
    delete window;
    SDL_Quit();
}


bool Mesa::Quit(){
    return window->CloseWindow();
}


void Mesa::UpdateThis(){
    window->Update();
    window->Draw();
}