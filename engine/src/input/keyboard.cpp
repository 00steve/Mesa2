#include "../../include/input/keyboard.h"



bool Keyboard::APressed(){
    return Input::KeyboardKeyState(SDLK_a);
}

bool Keyboard::DPressed(){
    return Input::KeyboardKeyState(SDLK_d);
}


bool Keyboard::KeyPressed(unsigned int keyCode){
    return Input::KeyboardKeyState(keyCode);
}

bool Keyboard::SpacePressed(){
    return Input::KeyboardKeyState(SDLK_SPACE);
}

bool Keyboard::SPressed(){
    return Input::KeyboardKeyState(SDLK_s);
}

bool Keyboard::WPressed(){
    return Input::KeyboardKeyState(SDLK_w);
}


bool Keyboard::operator[] (unsigned int keyCode){
    return false;
}