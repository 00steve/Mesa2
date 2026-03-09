#include "../include/viewport.h"


void Viewport::DrawThis(){
    if(!camera) return;
    //a+= 1;
    glClearColor(0.0, 0.0, 0.0, 0.6f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW); //set the vertex winding to clockwise
    //glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int width = 1280;
    int height = 720;
    
    glFrustum(-((float)width/((float)height))*2, ((float)width)/((float)height)*2, -2, 2, 2, 10.);
    glFrustum(-2,2, -2, 2, 1, 6);

    //double cameraX = std::sin(a*.01)*3;
    //double cameraZ = std::cos(a*.01)*3;
    //gluLookAt(cameraX, 0., cameraZ, 0., 0., 0., 0., 1., 0.);
    //glFrustum(-5,5, -5, 5, -5, 15);
    //gluLookAt(0, 0, -5, 0., 0., 0., 0., 1., 0.);

    Displayable::SetCurrentProjectionMatrix(camera->GetProjectionMatrix());
    Displayable::SetCurrentViewMatrix(camera->GetViewMatrix());

    glMatrixMode(GL_MODELVIEW);
    std::cout << "draw viewport the good one\n";

    SDL_GL_SwapWindow(GetCurrentSDLWindow());
}

void Viewport::SetCamera(Camera* newCamera){
    camera = newCamera;
}

Viewport::Viewport(){
    Name("Viewport");
}

Viewport::~Viewport(){
}
