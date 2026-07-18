#pragma once

#include <Managers/BaseManagers/RenderManager.h>
#include <Managers/ManagersFactoryRegistration.h>
#include <Graphics/RenderCommand.h>

namespace shen3
{
    class RenderQueue
        : public RenderManager
    {
    public:
        void Draw() override;

        void AddCommand(const RenderCommand& command);
        void ProcessCommands();
        void ClearCommands();
        void Sort();

    protected:
        virtual void ProcessCommand(const RenderCommand& command) = 0;

    protected:
        std::vector<RenderCommand> _commands;
    };
}
