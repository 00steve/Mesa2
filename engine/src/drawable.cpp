#include "../include/drawable.h"

void Drawable::Draw(){
    DrawThis();
}   

void Drawable::DrawThis(){
    // This function is meant to be overridden by derived classes to implement specific drawing behavior.
    // The base implementation does nothing.
}