#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <list>
#include <SDL2/SDL.h>


#include "node.h"
#include "drawable.h"
#include "viewport.h"


class Window : virtual public Node, virtual public Drawable {
private:

    SDL_Event event;
    bool closeWindow = false;
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
    std::list<Viewport*> viewports;

protected:
    void DrawThis() override;
    void UpdateThis() override;

public:
    bool CloseWindow();
    Window();
    ~Window();


};



#endif