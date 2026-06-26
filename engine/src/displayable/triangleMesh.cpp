#include "../../include/displayable/triangleMesh.h"



void triangleMesh::DrawThis(){
    //glColor3d(colors[0]->x, colors[0]->y, colors[0]->z); glVertex3d(vertices[0]->x, vertices[0]->y, vertices[0]->z);
}


triangleMesh::triangleMesh(){
    
}


triangleMesh::triangleMesh(unsigned int colorCount, unsigned int vertexCount, unsigned int triangleCount){
    this->colorCount = colorCount;
    this->triangleCount = triangleCount;
    this->vertexCount = vertexCount;

    //allocate arrays
    colors = new double3[colorCount];
    triangles = new triangle[triangleCount];
    vertices = new double3[vertexCount];
}


triangleMesh::~triangleMesh(){
    delete[] colors;
    delete[] triangles;
    delete[] vertices;
}