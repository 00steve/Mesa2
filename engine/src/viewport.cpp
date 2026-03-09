#include "../include/viewport.h"


void Viewport::DrawThis(){
    // Fill the surface white
    SDL_Surface* surface = GetCurrentSDLSurface();
    SDL_Window* window = GetCurrentSDLWindow();

    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    // Update the window surface to show the changes
    SDL_UpdateWindowSurface(window);
}

Viewport::Viewport(){
    Name("Viewport");
}

Viewport::~Viewport(){
}
