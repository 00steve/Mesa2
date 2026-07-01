#include <iostream>
#include <SDL2/SDL.h>


#include "../include/mesa.h"
#include "../include/scene/fps.h"


int main(int argc, char** args) {
    Mesa mesa;
    FirstPersonShooter fps;
    mesa.AddChild(&fps);

    while(!mesa.Quit()){
        mesa.Update();
    }
	return 0;
}