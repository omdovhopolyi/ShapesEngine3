#pragma once

#include <Managers/BaseManagers/UpdateManager.h>

namespace shen3
{
    class SDLMainWindow final
        : public UpdateManager
    {
        MANAGERS_FACTORY(SDLMainWindow)

    public:
        void Load() override;
        void Start() override;
        void Update() override;
        void Stop() override;

        void SwapBuffers();

    private:
        void CreateMainWindow();
    };
}
