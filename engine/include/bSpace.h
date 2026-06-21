#ifndef UTILS_BSpace
#define UTILS_BSpace

#include "aabb.h"
#include "displayable.h"

class BSpace : public Displayable {
private:
    AABB bounds;
    glm::vec3 lineColor;
    std::vector<float> vertexL;

    void Init();

protected:
    void CustomDraw();

public:
    BSpace(AABB bounds);

};

#endif