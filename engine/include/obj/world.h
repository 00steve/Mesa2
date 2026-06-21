#ifndef UTILS_World
#define UTILS_World

#include "../displayable.h"
#include "../bSpace.h"
#include "../timer.h"

/*
contains objects like the b-space to handle collision, and rules, and 
other information needed to run the engine.
*/

class World : public Displayable {
private:
    BSpace* space;
    Timer timer;

protected:
    void CustomDraw();
    void CustomUpdate();

public:
    void SetSize(double3 min, double3 max);

};





#endif