#include <SDL/SDLMainWindow.h>

#include <Logger/Logger.h>
#include <Messenger/Messenger.h>
#include <Messenger/Events/Common.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include <SDL3/SDL.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(SDLMainWindow)

    void SDLMainWindow::Init(ManagersController* managersController)
    {
        UpdateManager::Init(managersController);
        InitSubscriptions();
    }

    void SDLMainWindow::Load()
    {
        CreateMainWindow();
    }

    void SDLMainWindow::Start()
    {
        BroadcastWindowSize();
    }
    
    void SDLMainWindow::Update()
    {
        
    }

    void SDLMainWindow::Stop()
    {

    }

    void SDLMainWindow::SwapBuffers()
    {
        SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
    }

    void SDLMainWindow::CreateMainWindow()
    {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        _window = SDL_CreateWindow(
            "test",
            1280,
            720,
            SDL_WINDOW_OPENGL
        );

        if (!_window) {
            Logger::Err("Failed to create SDL window");
            return;
        }

        SDL_GLContext context = SDL_GL_CreateContext(_window);
        if (!context) {
            Logger::Err("Failed to create GL context");
            return;
        }

        SDL_GL_MakeCurrent(_window, context);

        if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
            Logger::Err("GLAD init failed");
            return;
        }

        SDL_CaptureMouse(true);
        SDL_HideCursor();
        SDL_SetWindowRelativeMouseMode(_window, true);
    }

    void SDLMainWindow::InitSubscriptions()
    {
        _subscriptions.Subscribe<RequestMainWindowSize>([this](const auto&) {
            BroadcastWindowSize();
        });
    }

    void SDLMainWindow::BroadcastWindowSize()
    {
        int width = 0;
        int height = 0;
        SDL_GetWindowSize(_window, &width, &height);
        Messenger::Instance().Broadcast<WindowResized>(width, height);
    }
}
