#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include "../scene.h"
//#include "../viewport/viewport2d.h"

class LoadingScreen : virtual public Scene {
private:
    TTF_Font* font;
    SDL_Color color = { 255, 255, 255, 255 }; // White
    SDL_Surface* surface;
    SDL_Texture* texture;
protected:
    //void DrawThis() override;
    //void UpdateThis() override;

public:
    LoadingScreen();
    ~LoadingScreen();

};


#endif