#ifndef VIEWPORT3D_H
#define VIEWPORT3D_H

#include "../viewport.h"
#include "../timer.h"

class Viewport3d : public Viewport, public Timer {
private:
    double y = 0;


protected:
    void DrawThis() override;
    void UpdateThis() override;


public:
    Viewport3d();
    ~Viewport3d();

    
};

#endif