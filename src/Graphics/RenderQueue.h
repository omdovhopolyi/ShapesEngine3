#pragma once

#include <Managers/BaseManagers/UpdateManager.h>
#include <Managers/ManagersFactoryRegistration.h>
#include <Graphics/RenderCommand.h>

namespace shen3
{
    class RenderQueue
        : public UpdateManager
    {
        MANAGERS_FACTORY(RenderQueue)

    public:
        void Update() override;

        void AddCommand(RenderCommand& command);
        void ProcessCommands();
        void ClearCommands();
        void Sort();

    private:
        std::vector<RenderCommand> _commands;
    };
}
