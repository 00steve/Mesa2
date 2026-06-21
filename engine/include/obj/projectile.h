#ifndef UTILS_Projectile
#define UTILS_Projectile

#include "../displayable/line.h"
#include "../physical.h"
#include "../timer.h"

class Projectile : public line, public Physical, public Timer{
private:
    double3 velocity;


protected:
    virtual void DrawThis();
    virtual void CustomUpdate();

public:
    Projectile(double3 position, double3 velocity);
    ~Projectile();

};




#endif