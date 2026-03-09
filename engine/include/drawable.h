#ifndef DRAWABLE_H
#define DRAWABLE_H 

#include "node.h"

class Drawable : virtual public Node {
    
protected:
    virtual void DrawThis();


public:
    void Draw();


};



#endif