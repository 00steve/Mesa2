#include "../include/input.h"


int2 Input::CursorMovement(){
    return cursorMovement;
}


void Input::KeyboardKeyDown(unsigned int keyCode){
    std::cout << "pressed key : " << keyCode << std::endl;
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

/*
int2 Input::WindowCursorPosition(){
    return windowCursorPosition;
}
*/

void Input::CursorMovement(unsigned int x, unsigned int y){
    cursorMovement = int2(x,y);
}