#ifndef UTILS_MOUSE_H
#define UTILS_MOUSE_H

#include "../input.h"

class Mouse : public Input {
private:
    int2 currentWindowCursorPosition;
    bool cursorMoved;
    int2 cursorMovement;
    int2 lastWindowCursorPosition;

public:
    void CheckCursorMovement();
    bool CursorMoved();
    int2 GetWindowCursorMovement();

};

#endif