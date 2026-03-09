#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>


#include "node.h"
#include "drawable.h"


class Window : virtual public Node, virtual public Drawable {
private:

    SDL_Event event;
    bool quit = false;
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;


protected:
    virtual void DrawThis() override;
    virtual bool UpdateThis() override;

public:
    Window();
    ~Window();


};



#endif