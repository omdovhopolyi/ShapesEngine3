#pragma once

#include <Managers/BaseManagers/UpdateManager.h>
#include <Messenger/SubscriptionsContainer.h>

struct SDL_Window;

namespace shen3
{
    class SDLMainWindow final
        : public UpdateManager
    {
        MANAGERS_FACTORY(SDLMainWindow)

    public:
        void Init(ManagersController* managersController);
        void Load() override;
        void Start() override;
        void Update() override;
        void Stop() override;

        void SwapBuffers();

    private:
        void CreateMainWindow();
        void InitSubscriptions();
        void BroadcastWindowSize();

    private:
        SDL_Window* _window = nullptr;
        SubcriptionsContainer _subscriptions;
    };
}
