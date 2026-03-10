#include "../include/viewport.h"


void Viewport::DrawThis(){
    if(!camera) return;

    x += .01;
    if(x > 1) x =  0;

    int2 screenSize = Displayable::GetScreenSize();


    //setuip current OpenGL settings and such
    glClearColor(0.0, 0, 0.3, 0.6f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW); //set the vertex winding to clockwise
    //glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);    

    //set it to configure the projection matrix and then load the current 
    //camera projection matrix settings
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glMultMatrixf(glm::value_ptr(*camera->GetProjectionMatrix()));

    //set it back to model projection, so all of the child nodes can
    //be rendered in the modelview matrix where they belong with the 
    //camera view matrix already applied and all of that good shit.
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,(GLsizei)screenSize.x,(GLsizei)screenSize.y);

}

void Viewport::SetCamera(Camera* newCamera){
    camera = newCamera;
}

void Viewport::SetCameraPosition(double3 newCameraPosition){
    if(!camera) return;
    camera->SetPosition(newCameraPosition);
}

Viewport::Viewport(){
    Name("Viewport");
}

Viewport::~Viewport(){
}
