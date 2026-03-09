#ifndef MESA_H
#define MESA_H



#include "node.h"
#include "window.h"
#include "scene/loadingScreen.h"
#include "viewport/viewport2d.h"

class Mesa : virtual public Node{
private:
    Window* window = NULL;
    LoadingScreen* loadingScreen = NULL;
    Viewport2d* viewport2d = NULL;

private:
    virtual void UpdateThis() override;


public:
    Mesa();
    ~Mesa();
    bool Quit();


};


#endif