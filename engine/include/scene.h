#ifndef SCENE_H
#define SCENE_H

#include "node.h"
#include "displayable.h"
#include "viewport.h"

class Scene : virtual public Displayable {
private:
    Viewport* viewport = NULL;

protected:
    virtual void SetWindowProperties();

public:
    Viewport* GetViewport();
    Scene();
    ~Scene();
};

#endif