#pragma once

#include <Managers/BaseManagers/UpdateManager.h>
#include <Managers/ManagersFactoryRegistration.h>
#include <Scene/Scene.h>

#include <memory>

namespace shen3
{
    class ScenesManager final
        : public UpdateManager
    {
        MANAGERS_FACTORY(ScenesManager)

    public:
        void Update() override;

    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
    };
}
