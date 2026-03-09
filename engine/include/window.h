#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "node.h"
#include "displayable.h"
#include "viewport.h"
#include "config/graphicsConfig.h"


class Window : virtual public Node, virtual public Displayable {
private:

    SDL_Event event;
    bool closeWindow = false;
    SDL_GLContext glContext;
	SDL_Surface* surface = NULL;
    std::vector<Viewport*> viewports;
	SDL_Window* window = NULL;

protected:
    bool AddChildThis(Node* newChild) override;
    void DrawThis() override;
    void UpdateThis() override;


public:
    bool CloseWindow();
    Window();
    ~Window();


};



#endif