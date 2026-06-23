#include "../../include/input/mouse.h"

void Mouse::CheckCursorMovement(){
    //lastWindowCursorPosition = currentWindowCursorPosition;
    //currentWindowCursorPosition = WindowCursorPosition();
    //cursorMovement = currentWindowCursorPosition-lastWindowCursorPosition;
    cursorMovement = CursorMovement();
    cursorMoved = cursorMoved || cursorMovement.x != 0 || cursorMovement.y != 0;
}


bool Mouse::CursorMoved(){
    return cursorMoved;
}


int2 Mouse::GetWindowCursorMovement(){
    if(!cursorMoved){
        return cursorMovement = int2(0,0);
    }
    cursorMoved = false;
    return cursorMovement;
}