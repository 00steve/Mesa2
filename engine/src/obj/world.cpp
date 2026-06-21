#include "../../include/obj/world.h"

void World::CustomDraw(){

    space->Draw();
}

void World::CustomUpdate(){
    timer.Update();
    EmptyGarbage();
}

void World::SetSize(double3 min, double3 max){
    if(space){
        //do stuff to clear out the space
    }
    space = new BSpace(AABB(min,max));
}