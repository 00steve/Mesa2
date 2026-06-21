#include "../include/int2.h"

int2::int2(){
    x = 0;
    y = 0;
}

int2::int2(int x, int y){
    this->x = x;
    this->y = y;
}

bool int2::operator == (int2 other){
    return x == other.x && y == other.y;
}
bool int2::operator != (int2 other){
    return x != other.x || y != other.y;
}
int2 int2::operator + (int2 other){
    return int2(x + other.x, y + other.y);
}
int2 int2::operator - (int2 other){
    return int2(x - other.x, y - other.y);
}

bool int2::operator == (int other){
    return x * x + y * y == other * other;
}
bool int2::operator != (int other){
    return x * x + y * y != other * other;
}
int2 int2::operator * (int other){
    return int2(x * other, y * other);
}
int2 int2::operator / (int other){
    return int2(x / other, y / other);
}
int2 int2::operator + (int other){
    return int2(x + other, y + other);
}
int2 int2::operator - (int other){
    return int2(x - other, y - other);
}
