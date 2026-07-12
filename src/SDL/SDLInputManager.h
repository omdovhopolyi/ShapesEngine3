#pragma once

#include <Managers/BaseManagers/PlayerWindowInputManager.h>
#include <Managers/ManagersFactoryRegistration.h>

namespace shen3
{
    class SDLInputManager
        : public PlayerWindowInputManager
    {
        MANAGERS_FACTORY(SDLInputManager)

    public:
        void Update() override;

        std::string GetCharByKey(int key) const override;
        int GetKeyByChar(const std::string& charKeyStr, bool silent = false) const override;

    protected:
        void GenerateCharKeyMap() override;
    };
}
