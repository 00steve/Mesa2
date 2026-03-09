#ifndef MESA_H
#define MESA_H



#include "node.h"
#include "window.h"


class Mesa : virtual public Node{
private:
    Window* window;


private:
    virtual bool UpdateThis() override;


public:
    Mesa();
    ~Mesa();


};


#endif