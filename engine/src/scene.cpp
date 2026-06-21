#include "../include/scene.h"

Viewport* Scene::GetViewport(){
    return viewport;
}

Scene::Scene(){
}

Scene::~Scene(){
}

Viewport* Scene::SetViewport(Viewport* newViewport){
    if(viewport) RemoveThisDependency(viewport);
    AddDependency(newViewport);
    return viewport = newViewport;
}