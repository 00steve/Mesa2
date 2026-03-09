#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <SDL2/SDL.h>

#include "node.h"
#include "displayable.h"
#include "obj/camera.h"

class Viewport : virtual public Node, virtual public Displayable {
private:
    Camera* camera = NULL;

protected:
    void DrawThis() override;
    void SetCameraPosition(double3 newCameraPosition);

public:
    void SetCamera(Camera* newCamera);
    Viewport();
    ~Viewport();


};

#endif