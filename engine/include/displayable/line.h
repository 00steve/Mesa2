#ifndef UTIL_Line
#define UTIL_Line

#include <vector>

#include "../double3.h"
#include "../displayable.h"

class line : public Displayable {
private:
    double3** colors = NULL;
    double len;
    glm::vec3 lineColor;
    std::vector<float> vertexL;
    double3** vertices = NULL;
    double3* internalVertices = NULL;

public:
    void AssignColors(double3* c0, double3* c1);
    void AssignVertices(double3* v0, double3* v1);
    void DrawThis();
    void Init(double3* v0, double3* v1,double3* c0, double3* c1);
    line();
    line(double3 v0, double3 v1);
    line(double3* v0, double3* v1);
    ~line();
    bool SetShader(std::string shader);
    bool UpdateVertices(double3 v0, double3 v1);
};


#endif