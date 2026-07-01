#include "../include/displayable.h"

//static class member initializations
//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

glm::mat4* Displayable::currentProjectionMatrix = NULL;
glm::mat4* Displayable::currentViewMatrix = NULL;
std::string Displayable::defaultShaderDirectory = "../shaders/";
unsigned int Displayable::drawableCount = 0;
SDL_GLContext* Displayable::glContext = NULL;
GraphicsConfig Displayable::graphicsConfig = GraphicsConfig();
bool Displayable::initialized = false;
std::map<std::string, ShaderMap> Displayable::shaderMaps;
SDL_Surface* Displayable::surface = NULL;
SDL_Window* Displayable::window = NULL;



std::vector<float3> Displayable::ConvertNumbersToVectors(std::vector<float> floats,std::vector<uint> indices){
    std::vector<float3> vectors;
    if(indices.size() % 3){
        std::cout << "indices has " << indices.size() << " values. The number of values must be evenly divisible by 3.\n";
        return vectors;
    }
    std::vector<uint>::iterator i = indices.begin();
    while(i != indices.end()){
        uint xI = *i++;
        uint yI = *i++;
        uint zI = *i++;
        vectors.push_back(float3(floats[xI],floats[yI],floats[zI]));

        //vectors.push_back(float3(floats[*i++],floats[*i++],floats[*i++])); //don't use this. For some reason it reverses the x,y,z
    }
    return vectors;
}

std::vector<float> Displayable::ConvertNumbersToLineStrip(std::vector<float> floats,std::vector<uint> indices){
    std::vector<float> lineStrip;
    if(indices.size() % 3){
        std::cout << "indices has " << indices.size() << " values. The number of values must be evenly divisible by 3.\n";
        return lineStrip;
    }
    std::vector<uint>::iterator i = indices.begin();
    while(i != indices.end()){
        lineStrip.push_back(floats[*i++]);
    }
    return lineStrip;
}

std::vector<float> Displayable::ConvertVectorsToLineStrip(std::vector<float3> vectors,std::vector<uint> indices){
    std::vector<float> lineStrip;
    std::vector<uint>::iterator i = indices.begin();
    while(i != indices.end()){
        lineStrip.push_back(vectors[*i].x);
        lineStrip.push_back(vectors[*i].y);
        lineStrip.push_back(vectors[*i].z);
        ++i;
    }
    return lineStrip;
}

bool Displayable::AddChildThis(Node* newChild){
    Displayable* nc = dynamic_cast<Displayable*>(newChild);
    if(!nc) return false;
    drawableChildren.push_back(nc);
    return true;
}

void Displayable::DrawThis(){
    //std::cout << "no draw implemented for node: " << Name() << std::endl;
}

void Displayable::CustomRemoveDependency(Node* oldDependency){
    //remove displayable reference
    for(std::vector<Displayable*>::iterator oc = drawableChildren.begin(); oc != drawableChildren.end(); ){
        if(*oc != oldDependency) {
            ++oc;
            continue;
        }
        drawableChildren.erase(oc);
        std::cout << " - remove displayable : " << oldDependency->Name() << std::endl;
        return;
    }
}

Displayable::Displayable(){
    ++drawableCount;
}

Displayable::~Displayable(){
    --drawableCount;
    //if no drawables are left, unload everything
    if(!drawableCount){
        std::cout << "no drawables left, terminate any static stuff\n";
        initialized = false;
        //glfwTerminate();
    }
}

void Displayable::Draw(){
    DrawThis();
    DrawChildren();
}

void Displayable::DrawChildren(){
    for(std::vector<Displayable*>::iterator child = drawableChildren.begin(); child != drawableChildren.end(); ){
        (*child)->Draw();
        ++child;
    }
}

ShaderMap* Displayable::FindShaderMap(std::string shaderName){
    if(shaderMaps.find(shaderName) == shaderMaps.end()) return NULL;
    return &shaderMaps.at(shaderName);
}

SDL_GLContext* Displayable::GetCurrentGLContext(){
    return glContext;
}

ShaderMap* Displayable::GetCurrentShaderMap(){
    return shaderMap;
}

glm::mat4 Displayable::GetCurrentProjectionMatrix(){
    return *currentProjectionMatrix;
}

SDL_Surface* Displayable::GetCurrentSDLSurface(){
    return surface;
}

glm::mat4 Displayable::GetCurrentViewMatrix(){
    return *currentViewMatrix;
}

SDL_Window* Displayable::GetCurrentSDLWindow(){
    return window;
}

int2 Displayable::GetScreenSize(){
    return graphicsConfig.GetScreenSize();
}

float Displayable::GetViewRatio(){
    return graphicsConfig.GetViewRatio();
}

bool Displayable::Init(){
        if(!initialized){
        std::cout<<"initialize displayable systems\n";
        //if (glfwInit()) {
        //    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
        //} else {
        //    std::cout << "Displayable error : failed to start stupid fucking glfw\n";
        //    return initialized;
        //}

 
        initialized = true;
    
    }
    return initialized;
}

void Displayable::LoadShaders(){
    std::vector<std::string> shaderFiles = FileUtil::FileList(defaultShaderDirectory);
    std::sort(shaderFiles.begin(),shaderFiles.end());
    unsigned int fCharIndex;
    unsigned int vCharIndex;
    unsigned int mode = 0;
    std::string shaderName;
    bool haveFS = false;
    for(std::vector<std::string>::iterator f = shaderFiles.begin(); f != shaderFiles.end(); ){
        fCharIndex = (*f).find("_f.txt");
        if(fCharIndex < 10000) mode = 0; //no matter what, if the current file is a fragment shader, reset the mode
        switch(mode){
        case 0: //looking for _f.txt
            if(fCharIndex > 9999) break;
            shaderName = (*f).substr(0,fCharIndex);
            mode = 1;
            break;
        case 1: //looking for _v.txt
            vCharIndex = (*f).find("_v.txt");
            if(vCharIndex > 9999) {
                mode = 0; //reset to look for fragment shader
                break;
            }
            std::string vName = (*f).substr(0,vCharIndex);
            if(vName != shaderName){
                mode = 0;
                break;
            }
            std::cout << " - load the shader (" << defaultShaderDirectory + shaderName + "_f.txt" << " , "
                << defaultShaderDirectory + shaderName + "_v.txt" << " , "
                << shaderName << "\n";
            LoadShaders(defaultShaderDirectory + shaderName + "_f.txt", defaultShaderDirectory + shaderName + "_v.txt", shaderName);
            mode = 0;
            break;
        }
        ++f;
    }
}

bool Displayable::LoadShaders(std::string fragmentShaderFilePath, std::string vertexShaderFilePath, std::string shaderName){

    ShaderMap newShaderMap;
    GLint isCompiled = 0;

    std::string fString = FileUtil::LoadPlainText(fragmentShaderFilePath);
    const char* fCode = fString.c_str();
    newShaderMap.fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(newShaderMap.fragmentShaderId, 1, &fCode, NULL);
    glCompileShader(newShaderMap.fragmentShaderId);
    glGetShaderiv(newShaderMap.fragmentShaderId, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE){   
        std::cout << " failed to compile fragment shader:\n" << fCode << std::endl;
        return false;
    }

    std::string vString = FileUtil::LoadPlainText(vertexShaderFilePath);
    const char* vCode = vString.c_str();
    newShaderMap.vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(newShaderMap.vertexShaderId, 1, &vCode, NULL);
    glCompileShader(newShaderMap.vertexShaderId);
    glGetShaderiv(newShaderMap.vertexShaderId, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE){   
        std::cout << " failed to compile vertex shader:\n" << vCode << std::endl;
        return false;
    }

    newShaderMap.shaderProgramId = glCreateProgram();
    //std::cout << "new shader ID : " << newShaderMap.shaderProgramId << std::endl;
    glAttachShader(newShaderMap.shaderProgramId, newShaderMap.vertexShaderId);
    glAttachShader(newShaderMap.shaderProgramId, newShaderMap.fragmentShaderId);
    glLinkProgram(newShaderMap.shaderProgramId);

    GLint isLinked = 0;
    glGetProgramiv(newShaderMap.shaderProgramId, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE)
    {
        std::cout << "failed to link program\n";
        return false;
    }

    /*check if shader with same name already exists. If it does,
    unload the existing shader objects from memory*/
    ShaderMap* oldShaderMap = FindShaderMap(shaderName);
    if(oldShaderMap){
        //std::cout << "remove old \"" << shaderName << "\" shader objects\n";
        glDeleteShader(oldShaderMap->fragmentShaderId);
        glDeleteShader(oldShaderMap->vertexShaderId);
        glDeleteProgram(oldShaderMap->shaderProgramId);
    }

    //store the new shader map
    Displayable::shaderMaps[shaderName] = newShaderMap;
    return true;
}

void Displayable::OnSetScreenSize(){
    for(std::vector<Displayable*>::iterator child = drawableChildren.begin(); child != drawableChildren.end(); ){
        (*child)->OnSetScreenSize();
        ++child;
    }
}

void Displayable::SetCurrentProjectionMatrix(glm::mat4* newProjectionMatrix){
    currentProjectionMatrix = newProjectionMatrix;
}

void Displayable::SetCurrentViewMatrix(glm::mat4* newViewMatrix){
    currentViewMatrix = newViewMatrix;
}

void Displayable::SetSDLSurface(SDL_Surface* newSurface){
    surface = newSurface;
}

void Displayable::SetSDLWindow(SDL_Window* newWindow){
    window = newWindow;
}

void Displayable::SetWindowSize(int2 newWindowSize){
    graphicsConfig.SetScreenSize(newWindowSize);
}