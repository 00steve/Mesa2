#include <iostream>
#include <SDL2/SDL.h>


#include "../include/mesa.h"
#include "../include/scene/fps.h"
#include "../include/scene/loadingScreen.h"


int main(int argc, char** args) {
    Mesa mesa;
    //FirstPersonShooter fps;
    //mesa.AddChild(&fps);
    LoadingScreen ls;
    mesa.AddChild(&ls);


    while(!mesa.Quit()){
        mesa.Update();
    }
	return 0;
}