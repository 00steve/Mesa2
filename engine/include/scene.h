#ifndef SCENE_H
#define SCENE_H

#include "node.h"
#include "displayable.h"
#include "viewport.h"

class Scene : virtual public Node, virtual public Displayable {
private:
    Viewport* viewport = NULL;

protected:
    Viewport* SetViewport(Viewport* newViewport);

public:
    Viewport* GetViewport();
    Scene();
    ~Scene();

};

#endif