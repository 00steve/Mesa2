#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <SDL2/SDL.h>

#include "node.h"
#include "displayable.h"

class Viewport : virtual public Node, virtual public Displayable {
private:
    

protected:
    void DrawThis() override;
    //void UpdateThis() override;


public:
    Viewport();
    ~Viewport();


};

#endif