#include <iostream>

#include <Engine/Engine.h>
//#define GLAD_GL_IMPLEMENTATION
//#include <glad/gl.h>
//#include <SDL3/SDL.h>

int main()
{
    shen3::Engine engine;
    engine.Initialize();
    engine.Run();
    engine.Destroy();

    //SDL_Init(SDL_INIT_VIDEO);

    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //auto window = SDL_CreateWindow(
    //    "test",
    //    1280,
    //    720,
    //    SDL_WINDOW_OPENGL
    //);

    //if (!window) {
    //    std::cout << "Failed to create SDL window" << std::endl;
    //    //Logger::Err("Failed to create SDL window");
    //    return 1;
    //}

    //SDL_GLContext context = SDL_GL_CreateContext(window);
    //if (!context) {
    //    std::cout << "Failed to create GL context" << std::endl;
    //    //Logger::Err("Failed to create GL context");
    //    return 1;
    //}

    //SDL_GL_MakeCurrent(window, context);

    //if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
    //    std::cout << "GLAD init failed" << std::endl;
    //    return 1;
    //    //Logger::Err("GLAD init failed");
    //}

    //bool needClose = false;
    //SDL_Event event;
    //while (!needClose) {
    //    SDL_PollEvent(&event);
    //    if (event.type == SDL_EVENT_QUIT) {
    //        break;
    //    }
    //}

    return 0;
}
