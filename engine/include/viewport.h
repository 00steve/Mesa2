#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "node.h"
#include "drawable.h"

class Viewport : virtual public Node, virtual public Drawable {
private:
    

protected:
    //void DrawThis() override;
    //void UpdateThis() override;


public:
    Viewport();
    ~Viewport();


};

#endif