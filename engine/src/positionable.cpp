#include "../include/positionable.h"

AABB* Positionable::GetAABB(){
    return &aabb;
}

double3 Positionable::GetPosition(){
    return currentPosition;
}

double3* Positionable::PositionPtr(){
    return &currentPosition;
}

double3 Positionable::GetPreviousPosition(){
    return previousPosition;
}

double3* Positionable::PreviousPositionPtr(){
    return &previousPosition;
}

void Positionable::OnSetPosition(){
    aabb.Reset();
    aabb.UpdateBounds(previousPosition);
    aabb.UpdateBounds(currentPosition);
    //std::cout << "pos : (" << previousPosition.x << "," << previousPosition.y << "," << previousPosition.z << ")\n";
    //std::cout << "min : (" << aabb.LowerBounds().x << "," << aabb.LowerBounds().y << "," << aabb.LowerBounds().z << ")\n";
    //std::cout << "max : (" << aabb.UpperBounds().x << "," << aabb.UpperBounds().y << "," << aabb.UpperBounds().z << ")\n";
}

Positionable::Positionable(){
    OnSetPosition();
}

double3 Positionable::SetPosition(double3 newPosition){
    previousPosition = currentPosition;
    currentPosition = newPosition;
    OnSetPosition();
    return currentPosition;
}