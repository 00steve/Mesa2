#include "../include/window.h"


void Window::DrawThis(){
    // Fill the surface white
    SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 255, 255));

    // Update the window surface to show the changes
    SDL_UpdateWindowSurface(window);
}



bool Window::UpdateThis(){
    while (SDL_PollEvent(&event) != 0) {
        // Check the type of event and handle it
        switch (event.type) {
            case SDL_QUIT:
                quit = true; // User clicked the window's close button
                break;
            case SDL_KEYDOWN:
                // Handle key presses
                // You can check specific keys using e.key.keysym.sym (e.g., SDLK_RETURN)
                break;
            case SDL_KEYUP:
                // Handle key releases
                break;
            case SDL_MOUSEMOTION:
                // Handle mouse movement (e.g., using e.motion.x and e.motion.y)
                break;
            // Add cases for other events like mouse clicks, window events, etc.
        }
    }

    return !quit;
}




Window::Window(){

    // Create our window
    window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN );

    // Make sure creating the window succeeded
    if ( !window ) {
        std::cout << "Error creating window: " << SDL_GetError()  << std::endl;
        exit(1);
    }

    // Get the surface from the window
    winSurface = SDL_GetWindowSurface( window );

    // Make sure getting the surface succeeded
    if ( !winSurface ) {
        std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
        exit(1);
    }

}


Window::~Window(){
    SDL_DestroyWindow(window);
}