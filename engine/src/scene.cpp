#include "../include/scene.h"

Viewport* Scene::GetViewport(){
    return viewport;
}

void Scene::SetWindowProperties(){
    
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