#include "../include/input.h"


//bool Input::KeyboardKey[105] = {};


void Input::KeyboardKeyDown(unsigned int keyCode){
    //std::cout << "pressed key : " << keyCode << std::endl;
    keyboardKey[keyCode] = true;
    return;
}

bool Input::KeyboardKeyState(unsigned int keyCode){
    return keyboardKey[keyCode];
}

void Input::KeyboardKeyUp(unsigned int keyCode){
    keyboardKey[keyCode] = false;
    return;
}

