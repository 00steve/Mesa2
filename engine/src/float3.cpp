#include "../include/float3.h"

float3::float3(){
}

float3::float3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

float3 float3::cross(float3 other){
    return float3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

float3 float3::cross(float3 a, float3 b){
    return float3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

float float3::dot(float3 other){
    return x * other.x + y * other.y + z * other.z;
}

float float3::dot(float3 a, float3 b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float3 float3::random(float rMin, float rMax, float gMin, float gMax, float bMin, float bMax){
    std::random_device rd;
    std::uniform_real_distribution<float> Runif(rMin,rMax);
    std::default_random_engine Rre{rd()};
    std::uniform_real_distribution<float> Gunif(gMin,gMax);
    std::default_random_engine Gre{rd()};
    std::uniform_real_distribution<float> Bunif(bMin,bMax);
    std::default_random_engine Bre{rd()};
    return float3(
        Runif(Rre),
        Gunif(Gre),
        Bunif(Bre)
    );
}

float3 float3::randomRGB(){
    std::random_device rd;
    std::uniform_real_distribution<float> unif(0,1);
    std::default_random_engine re{rd()};
    return float3(
        unif(re),
        unif(re),
        unif(re)
    );
}

float3 float3::getNormalized(){
    float l = length();
    return float3(x / l,y / l, z / l);
}

float float3::length(){
    return std::sqrt(x*x + y*y + z*z);
}

float3 float3::normalize(){
    float l = length();
    x /= l;
    y /= l;
    z /= l;
    return float3(x,y,z);
}

float float3::operator [] (int index){
    switch(index){
        case 0: return x;
        case 1: return y;
        case 2: return z;
    }
    return 0;
}

float3 float3::operator + (float3 other){
    return float3(x + other.x, y + other.y, z + other.z);
}
float3 float3::operator += (float3 other){
    return float3(x += other.x, y += other.y, z += other.z);
}
float3 float3::operator - (float3 other){
    return float3(x - other.x, y - other.y, z - other.z);
}
float3 float3::operator -= (float3 other){
    return float3(x -= other.x, y -= other.y, z -= other.z);
}
float3 float3::operator * (float3 other){
    return float3(x * other.x, y * other.y, z * other.z);
}
float3 float3::operator / (float3 other){
    return float3(x / other.x, y / other.y, z / other.z);
}

float3 float3::operator + (float other){
    return float3(x + other, y + other, z + other);
}
float3 float3::operator += (float other){
    return float3(x += other, y += other, z += other);
}
float3 float3::operator * (float other){
    return float3(x * other, y * other, z * other);
}
float3 float3::operator / (float other){
    return float3(x / other, y / other, z / other);
}

std::string float3::toString(){
    return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
}