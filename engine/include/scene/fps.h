#ifndef MESAFPS_H
#define MESAFPS_H


#include "../scene.h"
#include "../viewport/viewport3d.h"
#include "../obj/camera.h"
#include "../obj/projectile.h"
#include "../obj/cube.h"

class FirstPersonShooter : virtual public Scene {
private:
    void UpdateThis() override;
    
public:
    FirstPersonShooter();

};

#endif