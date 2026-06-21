#ifndef UTIL_KEYBOARD_H
#define UTIL_KEYBOARD_H


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

    bool operator[] (unsigned int keyCode);

};
#endif