#ifndef UTIL_Drawable
#define UTIL_Drawable

#define GLFW_INCLUDE_NONE

#include <vector>
#include <map>

#include <SDL2/SDL.h>
#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <GL/glx.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "node.h"
#include "fileUtil.h"
#include "double3.h"
#include "float3.h"
#include "graphicsConfig.h"

struct ShaderMap{
    unsigned int vertexShaderId;
    unsigned int fragmentShaderId;
    unsigned int shaderProgramId;
};

class Displayable : virtual public Node{
private:
    static glm::mat4* currentProjectionMatrix;
    static glm::mat4* currentViewMatrix;
    static std::string defaultShaderDirectory;
    std::vector<Displayable*> drawableChildren;
    static unsigned int drawableCount;
    static SDL_GLContext* glContext;
    static GraphicsConfig graphicsConfig;
    static bool initialized;
    static std::map<std::string, ShaderMap> shaderMaps;
	static SDL_Surface* surface;
	static SDL_Window* window;

    void DrawChildren();

protected:
    ShaderMap* shaderMap;
    glm::mat4 transformationMatrix;
    unsigned int VAO;
    unsigned int VBO;

    virtual bool AddChildThis(Node* newChild);
    virtual void DrawThis();
    virtual void CustomRemoveDependency(Node* oldDependency);
    Displayable();
    ~Displayable();

    virtual void OnSetScreenSize();
    
public:
    /**
     * @brief Given a list of floating point numbers, and a second list that contains
     * the lookup indices to the first list, build a single list x,y,z values representing
     * 3d vectors.\n <br></br>
     * \n <br></br>
     * This can be used to denormalize a small list of values that are repeated over
     * and over again. I don't know how to pass a list of floats and a bunch of index
     * lookups to them to GLSL, so I wrote this.
     * 
     * @param floats - The list of values to look up
     * @param indices - The list of which values to use to build the return list
     * @return std::vector<float3> 
     */
    static std::vector<float3> ConvertNumbersToVectors(std::vector<float> floats,std::vector<uint> indices);
    static std::vector<float> ConvertNumbersToLineStrip(std::vector<float> vectors,std::vector<uint> indices);
    static std::vector<float> ConvertVectorsToLineStrip(std::vector<float3> vectors,std::vector<uint> indices);

    /*the generic control function used to determine what is drawn for any drawable,
    yeah probably a garbage explination. It is called by all parent displayables, and 
    contains the code to call the CustomDraw() function that should be overwritten by 
    any inheriting classes and the code to call the Draw() function for any child 
    displayable objects, so just like call this shit and let everything do it's job.*/
    void Draw();

    /*gets shader map that has been loaded, if it exists. This returns a reference
    to the ShaderMap object. If a new ShaderMap is created by using LoadShaders() 
    and the same shaderName, it should replace the existing shader and any Displayable
    referencing that shader should update so they don't need to relink.
        A shaderMap contains a shader program that has been compiled, along with the 
    vertex shader comipled source reference and the fragment shader compiled source
    reference.*/
    static ShaderMap* FindShaderMap(std::string shaderName);

    /*Returns the current projection matrix reference that should be used to translate
    the opengl drawing stuff to correctly place the displayable on the screen.*/
    static glm::mat4 GetCurrentProjectionMatrix();

    /*If for some reason you need to know the reference to the shader program, and the 
    compiled vertex and fragment shaders of this displayable object. Call this and it 
    will return an object with those references. Congratulations.*/
    ShaderMap* GetCurrentShaderMap();

    static SDL_Surface* GetCurrentSDLSurface();
    
    /*Returns the current view matrix reference that should be used to translate the 
    opengl drawing stuff to correctly place the displayable based on where the camera is*/
    static glm::mat4 GetCurrentViewMatrix();

    static SDL_Window* GetCurrentSDLWindow();

    static SDL_GLContext* GetCurrentGLContext();


    static int2 GetScreenSize();

    /*based ont he pixel heigth and width of the window, return the ratio so it can 
    be used by graphics calculations to show an image that has the correct width and 
    height ratio*/
    static float GetViewRatio();

    /*Sets up the glfw() and other GL things. This should somehow be incorporated 
    into the code so it doesn't need to be called manually, like when the first 
    displayable is created, but I haven't found a good way to do that yet because 
    I'm a garbage person who writes code that should be shoved up a roadkilled walrus's
    asshole.*/
    static bool Init();

    /*give the relative path for the fragment and vertex shader, along with what the 
    name of the shader should be called. The name will be used to reference it by objects
    that want to draw.*/
    static bool LoadShaders(std::string fragmentShaderFilePath, std::string vertexShaderFilePath, std::string shaderName);

    /*Will scan the default shader path (Displayable::defaultShaderPath) directory
    for any pairs of text files that contain a [shader name]_v.txt and [shader name]_f.txt
    and try to load and build them. If there are any files that don't have pairs with the
    _v.txt and _f.txt, they will be ignored. */
    static void LoadShaders();
    /*Sets the current projection matrix that should be used by all displayables in the 
    scene.*/
    static void SetCurrentProjectionMatrix(glm::mat4* newProjectionMatrix);
    /*sets the current view matrix that should be used by all displayables in the scene*/
    static void SetCurrentViewMatrix(glm::mat4* newViewMatrix);

    /*store the current sdl window and sdl surface. Used by any SDL functions to draw things
    and probably OpenGL to creat contexts and other stuff like that*/
    static void SetSDLSurface(SDL_Surface* newSurface);
    static void SetSDLWindow(SDL_Window* newWindow);

    static void SetWindowSize(int2 newWindowSize);
};

#endif