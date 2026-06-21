#include "../../include/obj/projectile.h"

void Projectile::DrawThis(){
    line::DrawThis();
}

void Projectile::CustomUpdate(){
    SetPosition(GetPosition() + velocity * StepTime());
    velocity += Gravity() * StepTime();

    double et =LocalElapsedTime() ;
    if(et > 2 && !IsGarbage()){
        ThrowAway();
        std::cout << "throw away!\n";
    }
    //std::cout << PositionPtr() << " - " << PositionPtr()->y << "\n";
    /*std::cout << "aabb : " << GetAABB()->LowerBounds().x << "," << GetAABB()->LowerBounds().y << "," << GetAABB()->LowerBounds().z 
        << " - " << GetAABB()->UpperBounds().x << "," << GetAABB()->UpperBounds().y << "," << GetAABB()->UpperBounds().z <<  "\n";*/
}

Projectile::Projectile(double3 position, double3 velocity) :
        Physical(),
        line(PositionPtr(),PreviousPositionPtr()),
        velocity(velocity) {
    
}

Projectile::~Projectile(){

}