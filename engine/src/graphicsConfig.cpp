#include "../include/graphicsConfig.h"

int2 GraphicsConfig::GetScreenSize(){
    return screenSize;
}

float GraphicsConfig::GetViewRatio(){
    return viewRatio;
}

GraphicsConfig::GraphicsConfig(){
    screenSize = int2(800,600);
    SetViewRatio();
}

GraphicsConfig::GraphicsConfig(int2 screenSize){
    this->screenSize = screenSize;
    SetViewRatio();
}

int2 GraphicsConfig::SetScreenSize(int2 newScreenSize){
    screenSize = newScreenSize;
    SetViewRatio();
    return screenSize;
}

void GraphicsConfig::SetViewRatio(){
    viewRatio = (float)screenSize.x / (float)screenSize.y;
}