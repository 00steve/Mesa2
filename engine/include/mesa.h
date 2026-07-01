#ifndef MESA_H
#define MESA_H

#include <stack>

#include "graphicsConfig.h"
#include "input.h"
#include "node.h"
#include "displayable.h"
#include "window.h"
#include "scene.h"
//#include "scene/loadingScreen.h"
#include "viewport/viewport3d.h"
#include "obj/camera.h"
#include "obj/projectile.h"
#include "obj/cube.h"

class Mesa : virtual public Node, virtual public Displayable {
private:
    Scene* currentScene = NULL;
    std::stack<Scene*> scenes;
    Window* window = NULL;

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