#include "../../include/scene/loadingScreen.h"


LoadingScreen::LoadingScreen(){
    font = TTF_OpenFont("../../fonts/ToThePointRegular-n9y4.ttf", 24);

    surface = TTF_RenderText_Solid(font, "Hello World", color);
    //texture = SDL_CreateTextureFromSurface(renderer, surface);

    Name("Loading Screen");
}

LoadingScreen::~LoadingScreen(){
}
