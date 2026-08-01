#pragma once

#include <Managers/BaseManagers/RenderManager.h>
#include <Managers/ManagersFactoryRegistration.h>
#include <Graphics/RenderCommand.h>

namespace shen3
{
    class CameraComponent;

    class RenderQueue
        : public RenderManager
    {
    public:
        void Draw() override;

        void AddCommand(RenderCommand&& command);
        void ProcessCommands();
        void ClearCommands();
        void Sort();

    protected:
        void PrepareCommand(RenderCommand& command, CameraComponent* camera);
        virtual void ProcessCommand(const RenderCommand& command) = 0;

    protected:
        std::vector<RenderCommand> _commands;
    };
}
