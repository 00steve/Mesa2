#ifndef GRAPHICS_CONFIG_H
#define GRAPHICS_CONFIG_H

#include "int2.h"

class GraphicsConfig {
private:
    int2 screenSize; 
    float viewRatio;

    void SetViewRatio();



public: 
    int2 GetScreenSize();    
    float GetViewRatio();
    GraphicsConfig();
    GraphicsConfig(int2 screenSize);
    int2 SetScreenSize(int2 newScreenSize);
};

#endif