#include "../include/window.h"



bool Window::AddChildThis(Node* newChild){
    if(dynamic_cast<Viewport*>(newChild)){
        viewports.push_back(dynamic_cast<Viewport*>(newChild));
        AddDependency(newChild);
        return Displayable::AddChildThis(newChild);
    }
    return false;
}


bool Window::CloseWindow(){
    return closeWindow;
}


void Window::DrawThis(){
    SDL_GL_SwapWindow(window);
}



void Window::UpdateThis(){
    while (SDL_PollEvent(&event) != 0) {
        // Check the type of event and handle it
        switch (event.type) {
            case SDL_QUIT:
                closeWindow = true; // User clicked the window's close button
                break;
            case SDL_WINDOWEVENT_RESIZED:
                SetWindowSize(int2(event.window.data1, event.window.data2));
                break;
            case SDL_KEYDOWN:
                // Handle key presses
                // You can check specific keys using e.key.keysym.sym (e.g., SDLK_RETURN)
                break;
            case SDL_KEYUP:
                // Handle key releases
                break;
            case SDL_MOUSEMOTION:
                // Handle mouse movement (e.g., using e.motion.x and e.motion.y)
                break;
            // Add cases for other events like mouse clicks, window events, etc.
        }
    }
}




Window::Window(){

    //setup displayable global properties
    Displayable::SetSDLWindow(window);
    Displayable::SetSDLSurface(surface);



    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // Request double buffering as a GL attribute
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24); 
    // Request double buffering, which is common for smooth rendering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 


    // Create our window
    window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    // Make sure creating the window succeeded
    if ( !window ) {
        std::cout << "Error creating window: " << SDL_GetError()  << std::endl;
        exit(1);
    }

    // Get the surface from the window
    surface = SDL_GetWindowSurface( window );

    /*
    // Make sure getting the surface succeeded
    if ( !surface ) {
        std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
        exit(1);
    }
    */

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cout << "Error creating OpenGL context: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (SDL_GL_MakeCurrent(window, glContext) < 0) {
        std::cout << "Error making OpenGL context current: " << SDL_GetError() << std::endl;
        exit(1);
    }


    glewExperimental = GL_TRUE;
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    GLenum err = glewInit();
    if (err != GLEW_OK)
        exit(1);
    if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
        exit(1); // or handle the error in a nicer way


    Displayable::LoadShaders();

    Name("Game Window");
}


Window::~Window(){
    for(std::vector<Viewport*>::iterator oc = viewports.begin(); oc != viewports.end(); ){
        delete *oc;
        viewports.erase(oc);
    }
    SDL_DestroyWindow(window);
}