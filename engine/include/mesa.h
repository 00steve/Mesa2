#ifndef MESA_H
#define MESA_H



#include "node.h"
#include "displayable.h"
#include "window.h"
#include "scene/loadingScreen.h"
#include "viewport/viewport3d.h"

class Mesa : virtual public Node, virtual public Displayable {
private:
    Window* window = NULL;
    LoadingScreen* loadingScreen = NULL;
    Viewport3d* viewport3d = NULL;

protected:
    virtual bool AddChildThis(Node* newChild);
    virtual void DrawThis() override;
    virtual void UpdateThis() override;

public:
    Mesa();
    ~Mesa();
    bool Quit();


};


#endif