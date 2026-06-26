#include "../../include/displayable/triangle.h"

void triangle::AssignColors(double3* c0, double3* c1, double3* c2){
    if(!colors){
        colors = new double3*[3];
    }
    colors[0] = c0;
    colors[1] = c1;
    colors[2] = c2;
}
void triangle::AssignVertices(double3* v0, double3* v1, double3* v2){
    if(!vertices){
        vertices = new double3*[3];
    }
    vertices[0] = v0;
    vertices[1] = v1;
    vertices[2] = v2;
}

void triangle::DrawThis(){
    glColor3d(colors[0]->x, colors[0]->y, colors[0]->z); glVertex3d(vertices[0]->x, vertices[0]->y, vertices[0]->z);
    glColor3d(colors[1]->x, colors[1]->y, colors[1]->z); glVertex3d(vertices[1]->x, vertices[1]->y, vertices[1]->z);
    glColor3d(colors[2]->x, colors[2]->y, colors[2]->z); glVertex3d(vertices[2]->x, vertices[2]->y, vertices[2]->z);
}

void triangle::Init(double3* v0, double3* v1, double3* v2, double3* c0, double3* c1, double3* c2){
    AssignColors(c0, c1, c2);
    AssignVertices(v0, v1, v2);
}

triangle::triangle(){
    Init(new double3(), new double3(), new double3(), new double3(), new double3(), new double3());
}

triangle::triangle(double3* v0, double3* v1, double3* v2){
    Init(v0, v1, v2, new double3(), new double3(), new double3());
}

triangle::triangle(double3* v0, double3* v1, double3* v2, double3* c0, double3* c1, double3* c2){
    Init(v0, v1, v2, c0, c1, c2);
}

triangle::~triangle(){
    delete[] colors;
    delete[] vertices;
}