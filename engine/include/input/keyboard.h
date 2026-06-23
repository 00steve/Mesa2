#ifndef UTIL_KEYBOARD_H
#define UTIL_KEYBOARD_H

/* references
github.com/libsdl-org/SDL/blob/SDL2/include/SDL_keycode.h
*/


#include "../input.h"
#include <SDL2/SDL.h>


class Keyboard : public Input {
public:
    bool APressed();
    bool DPressed();
    bool KeyPressed(unsigned int keyCode);
    bool SpacePressed();
    bool SPressed();
    bool WPressed();

    //now working, don't know why. Will ignore for now.
    //bool operator[] (unsigned int keyCode);

};
#endif