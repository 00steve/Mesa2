#include <iostream>
#include <SDL2/SDL.h>


#include "../include/mesa.h"



int main(int argc, char** args) {
    Mesa mesa = Mesa();
    while(mesa.Update()){}
	return 0;
}