#ifndef UTIL_INPUT_H
#define UTIL_INPUT_H


#include <iostream>
#include "int2.h"


class Input {
private:
    inline static bool keyboardKey[300];
    //inline static int2 windowCursorPosition;
    inline static int2 cursorMovement;

protected:


public:
    static int2 CursorMovement();
    static void KeyboardKeyDown(unsigned int keyIndex);
    static bool KeyboardKeyState(unsigned int keyIndex);
    static void KeyboardKeyUp(unsigned int keyIndex);
    //static int2 WindowCursorPosition();
    static void CursorMovement(unsigned int x, unsigned int y);

};



#endif