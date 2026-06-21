#ifndef UTILS_Timer
#define UTILS_Timer

#include <GL/glew.h>
#include <SDL2/SDL.h>

class Timer{
private:
    static double currentGlfwTime;
    static double currentOffsetTime;
    static double elapsedTime;
    double localStartTime;
    static double previousGlfwTime;
    static int step;
    static double stepTime;

public:
    static double ElapsedTime();
    double LocalElapsedTime();
    static void Reset();
    static int Step();
    static double StepTime();
    Timer();
    static void Update();
};


#endif