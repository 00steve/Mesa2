#include "../../include/obj/camera.h"

Camera::Camera() : 
        cameraAngle(double3(0,0,0)),
        cameraMode(ManualKeyboardWASD1) {
    ResetProjectionMatrix();
    ResetViewMatrix();
    std::cout << "-  Create camera \n ";
}

Camera::~Camera(){

}

void Camera::DrawThis(){

}

glm::mat4* Camera::GetProjectionMatrix(){
    return &projectionMatrix;
}

glm::mat4* Camera::GetViewMatrix(){
    return &viewMatrix;
}

void Camera::OnSetPosition(){
    cameraPosition = Positionable::GetPosition();
    Positionable::OnSetPosition();
    RecalculateViewMatrix();
}

void Camera::SetMode(CameraMode newCameraMode){
    this->cameraMode = newCameraMode;
}

void Camera::UpdateThis(){
    cameraPosition = GetPosition();
    bool needsUpdate = false;
    double stepTime = StepTime();
    double3 newPosition = GetPosition();
    

    switch(cameraMode){
    case ManualKeyboardWASD1:
        if(keyboard.APressed()){
            cameraAngularVelocity.y += .6;
        }
        if (keyboard.DPressed()){
            cameraAngularVelocity.y -= .6;
        }
        if(keyboard.KeyPressed(SDLK_w)){
            cameraVelocity += 1;
        }
        if(keyboard.SPressed()){
            cameraVelocity -= 1;
        }

        cameraAngularVelocity.y *= 0.9;
        cameraVelocity *= .9;

        cameraAngle += cameraAngularVelocity.y * stepTime;
        cameraLinearVelocity.x = std::sin(cameraAngle.y)*cameraVelocity;
        cameraLinearVelocity.z = std::cos(cameraAngle.y)*cameraVelocity;
        cameraPosition.x += cameraLinearVelocity.x * stepTime;
        cameraPosition.z += cameraLinearVelocity.z * stepTime;
        //cameraPosition.z += cameraVelocity * stepTime;
        SetPositionAndRotation(cameraPosition, cameraAngle);
        break;

    case ManualKeyboardMouse2dMove:
        mouse.CheckCursorMovement();
        int2 winCursorMovement;
        float moveSpeed = .0024;
        if(mouse.CursorMoved()){
            winCursorMovement = mouse.GetWindowCursorMovement();
            cameraAngle -= double3(winCursorMovement.y * moveSpeed ,winCursorMovement.x * moveSpeed, 0);
            needsUpdate = true;
        }

        if(keyboard.APressed()){
            cameraLinearVelocity.x -= cameraLinearVelocityMax;
            needsUpdate = true;
        }
        if (keyboard.DPressed()){
            cameraLinearVelocity.x += cameraLinearVelocityMax;
            needsUpdate = true;
        }
        if(keyboard.WPressed()){
            cameraLinearVelocity.z += cameraLinearVelocityMax;
            needsUpdate = true;
        }
        if(keyboard.SPressed()){
            cameraLinearVelocity.z -= cameraLinearVelocityMax;
            needsUpdate = true;
        }

        cameraLinearVelocity *= 0.89;
        double3 lv = cameraLinearVelocity * stepTime;

        cameraPosition += double3(
            std::sin(cameraAngle.y)*lv.z - std::cos(cameraAngle.y)*lv.x,
            0,//std::cos(cameraAngle.x)*lv.z,
            std::cos(cameraAngle.y)*lv.z + std::sin(cameraAngle.y)*lv.x
        );

        if(needsUpdate){
            SetPositionAndRotation(cameraPosition, cameraAngle);
            std::cout << cameraPosition.x << "," << cameraPosition.y << "," << cameraPosition.z << std::endl;
        }
        break;

    };
}

void Camera::RecalculateViewMatrix(){
    viewMatrix = glm::lookAt(
        glm::vec3(GetPosition().x,GetPosition().y,GetPosition().z), // the position of your camera, in world space
        targetPosition,   // where you want to look at, in world space
        glm::vec3(0,1,0)        // probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
    );
    //std::cout << "Camera postion: " << GetPosition().toString() << std::endl;
}


void Camera::ResetProjectionMatrix(){
    float aspectRatio = GetViewRatio();
    projectionMatrix = glm::perspective(
        glm::radians(60.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
        aspectRatio,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
        0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
        100.0f             // Far clipping plane. Keep as little as possible.
    );
}


void Camera::ResetViewMatrix(){
    SetTargetPosition(double3(0,0,0));
    RecalculateViewMatrix();
}


void Camera::SetPositionAndRotation(double3 position, double3 rotation){
    SetPosition(position);
    SetTargetPosition(double3(
        position.x + std::sin(rotation.y)*std::cos(rotation.x),
        position.y + std::sin(rotation.x), 
        position.z + std::cos(rotation.y)*std::cos(rotation.x)
    ));
}


double3 Camera::SetTargetPosition(double3 newTargetPosition){
    targetPosition = glm::vec3(newTargetPosition.x,newTargetPosition.y,newTargetPosition.z);
    RecalculateViewMatrix();
    return newTargetPosition;
}