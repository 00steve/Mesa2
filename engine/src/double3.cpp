#include "../include/double3.h"

double3::double3(){
}

double3::double3(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

double3 double3::cross(double3 other){
    return double3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

double3 double3::cross(double3 a, double3 b){
    return double3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

double double3::dot(double3 other){
    return x * other.x + y * other.y + z * other.z;
}

double double3::dot(double3 a, double3 b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double3 double3::random(double rMin, double rMax, double gMin, double gMax, double bMin, double bMax){
    std::random_device rd;
    std::uniform_real_distribution<double> Runif(rMin,rMax);
    std::default_random_engine Rre{rd()};
    std::uniform_real_distribution<double> Gunif(gMin,gMax);
    std::default_random_engine Gre{rd()};
    std::uniform_real_distribution<double> Bunif(bMin,bMax);
    std::default_random_engine Bre{rd()};
    return double3(
        Runif(Rre),
        Gunif(Gre),
        Bunif(Bre)
    );
}

double3 double3::randomRGB(){
    std::random_device rd;
    std::uniform_real_distribution<double> unif(0,1);
    std::default_random_engine re{rd()};
    return double3(
        unif(re),
        unif(re),
        unif(re)
    );
}

double3 double3::getNormalized(){
    double l = length();
    return double3(x / l,y / l, z / l);
}

double double3::length(){
    return std::sqrt(x*x + y*y + z*z);
}

double3 double3::normalize(){
    double l = length();
    x /= l;
    y /= l;
    z /= l;
    return double3(x,y,z);
}

double double3::operator [] (int index){
    switch(index){
        case 0: return x;
        case 1: return y;
        case 2: return z;
    }
    return 0;
}

double3 double3::operator + (double3 other){
    return double3(x + other.x, y + other.y, z + other.z);
}
double3 double3::operator += (double3 other){
    return double3(x += other.x, y += other.y, z += other.z);
}
double3 double3::operator - (double3 other){
    return double3(x - other.x, y - other.y, z - other.z);
}
double3 double3::operator -= (double3 other){
    return double3(x -= other.x, y -= other.y, z -= other.z);
}
double3 double3::operator * (double3 other){
    return double3(x * other.x, y * other.y, z * other.z);
}
double3 double3::operator / (double3 other){
    return double3(x / other.x, y / other.y, z / other.z);
}

double3 double3::operator + (double other){
    return double3(x + other, y + other, z + other);
}
double3 double3::operator += (double other){
    return double3(x += other, y += other, z += other);
}
double3 double3::operator * (double other){
    return double3(x * other, y * other, z * other);
}
double3 double3::operator / (double other){
    return double3(x / other, y / other, z / other);
}

std::string double3::toString(){
    return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
}