#include "../../include/obj/cube.h"

void Cube::BuildFaces(){
    faces = new triangle[12]{
        triangle(&vertices[0],&vertices[1],&vertices[2],&colors[0],&colors[1],&colors[2]),
        triangle(&vertices[0],&vertices[2],&vertices[3],&colors[0],&colors[2],&colors[3]),
        triangle(&vertices[0],&vertices[3],&vertices[7],&colors[0],&colors[3],&colors[7]),
        triangle(&vertices[0],&vertices[7],&vertices[4],&colors[0],&colors[7],&colors[4]),
        triangle(&vertices[4],&vertices[7],&vertices[6],&colors[4],&colors[7],&colors[6]),
        triangle(&vertices[4],&vertices[6],&vertices[5],&colors[4],&colors[6],&colors[5]),
        triangle(&vertices[1],&vertices[5],&vertices[6],&colors[1],&colors[5],&colors[6]),
        triangle(&vertices[1],&vertices[6],&vertices[2],&colors[1],&colors[6],&colors[2]),
        triangle(&vertices[6],&vertices[7],&vertices[3],&colors[6],&colors[7],&colors[3]),
        triangle(&vertices[6],&vertices[3],&vertices[2],&colors[6],&colors[3],&colors[2]),
        triangle(&vertices[5],&vertices[1],&vertices[0],&colors[5],&colors[1],&colors[0]),
        triangle(&vertices[5],&vertices[0],&vertices[4],&colors[5],&colors[0],&colors[4])
    };
}

double3* Cube::BuildVertices(double size){
    return new double3[8]{
        double3(.5*size,.5*size,.5*size),
        double3(.5*size,.5*size,-.5*size),
        double3(-.5*size,.5*size,-.5*size),
        double3(-.5*size,.5*size,.5*size),
        double3(.5*size,-.5*size,.5*size),
        double3(.5*size,-.5*size,-.5*size),
        double3(-.5*size,-.5*size,-.5*size),
        double3(-.5*size,-.5*size,.5*size)
    };
}

/*This is really just a wrapper for the real cube constructor
where it just uses default values.*/
Cube::Cube(){
    Init(1);
}

Cube::Cube(double size){
    Init(size);
}

Cube::~Cube(){
    delete[] faces;
    delete[] colors;
    delete[] vertices;
}

void Cube::DrawThis(){
    glPushMatrix();

        glm::mat4 trans = glm::mat4(1.0f);
        double3 pos = GetPosition();
        trans = glm::translate(trans, glm::vec3(pos.x, pos.y, pos.z));
        //trans = glm::rotate(trans, (float)timer.LocalElapsedTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        glMultMatrixf(&trans[0][0]);

        glBegin(GL_TRIANGLES);
            for(int i=0;i<12;i++){
                faces[i].DrawThis();
            }
        glEnd();
    glPopMatrix();
}

void Cube::Init(const double size){
    this->size = size;
    colors = BuildVertices(2);
    vertices = BuildVertices(size);
    BuildFaces();
}