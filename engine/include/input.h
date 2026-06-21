#ifndef UTIL_INPUT_H
#define UTIL_INPUT_H


#include <iostream>


class Input {
private:
    inline static bool keyboardKey[300];

public:
    static void KeyboardKeyDown(unsigned int keyIndex);
    static bool KeyboardKeyState(unsigned int keyIndex);
    static void KeyboardKeyUp(unsigned int keyIndex);

};



#endif