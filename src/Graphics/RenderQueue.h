#pragma once

#include <Managers/BaseManagers/RenderManager.h>
#include <Managers/ManagersFactoryRegistration.h>
#include <Graphics/RenderCommand.h>

namespace shen3
{
    class RenderQueue
        : public RenderManager
    {
        MANAGERS_FACTORY(RenderQueue)

    public:
        void Draw() override;

        void AddCommand(RenderCommand& command);
        void ProcessCommands();
        void ClearCommands();
        void Sort();

    protected:
        std::vector<RenderCommand> _commands;
    };
}
