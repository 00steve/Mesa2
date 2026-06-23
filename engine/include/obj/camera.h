#ifndef OBJ_Camera
#define OBJ_Camera


#include "../input/keyboard.h"
#include "../input/mouse.h"

#include "../displayable.h"
#include "../physical.h"
#include "../timer.h"


enum CameraMode {
    ManualKeyboardWASD1,
    ManualKeyboardMouse1,
    FPS


};



class Camera : public Displayable, public Physical, public Timer {
private:
    CameraMode cameraMode;
    double3 cameraAngle;
    double3 cameraAngularAcceleration;
    double3 cameraAngularVelocity;
    double3 cameraLinearAcceleration;
    double3 cameraLinearVelocity;
    double3 cameraPosition;
    double cameraVelocity = 0;
    Keyboard keyboard;
    Mouse mouse;

    glm::mat4 projectionMatrix;
    glm::mat4 projectionMatrixDefault;
    glm::vec3 targetPosition;
    glm::mat4 viewMatrix;
    glm::mat4 viewMatrixDefault;




protected:
    void DrawThis() override;
    /*Implemented from the positionable class to call the recalculation of the 
    view matrix.*/
    void OnSetPosition() override;
    /*Called whenever the position of the camera or the camera's target position
    have changed so that the view matrix used by displayables is properly updated
    to reflect the new camera or target position.*/
    void RecalculateViewMatrix();

    void UpdateThis() override;

public:
    Camera();
    ~Camera();
    glm::mat4* GetProjectionMatrix();
    glm::mat4* GetViewMatrix();

    void ResetProjectionMatrix();
    void ResetViewMatrix();
    void SetPositionAndRotation(double3 position, double3 rotation);
    /*sets the camera to look at the new target position and returns the 
    new target position as well, because.... why not?*/
    double3 SetTargetPosition(double3 newTargetPosition);

};

#endif