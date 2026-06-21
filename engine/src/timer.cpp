#include "../include/timer.h"

double Timer::currentGlfwTime = (double)SDL_GetTicks64() / 1000.0;
double Timer::currentOffsetTime = 0;
double Timer::elapsedTime = 0;
double Timer::previousGlfwTime = Timer::currentGlfwTime;
int Timer::step = 0;
double Timer::stepTime = 0;

double Timer::LocalElapsedTime(){
    return elapsedTime - localStartTime;
}

void Timer::Reset(){
    currentOffsetTime = (double)SDL_GetTicks64() / 1000.0;
}

int Timer::Step(){
    return step;
}

double Timer::StepTime(){
    return stepTime;
}

Timer::Timer() : 
        localStartTime(elapsedTime) {
}

void Timer::Update(){
    previousGlfwTime = currentGlfwTime;
    currentGlfwTime = (double)SDL_GetTicks64() / 1000.0;
    ++step;
    stepTime = currentGlfwTime - previousGlfwTime;
    elapsedTime = currentGlfwTime - currentOffsetTime;
}