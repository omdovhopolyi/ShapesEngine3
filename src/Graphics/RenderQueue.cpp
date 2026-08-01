#include <Graphics/RenderQueue.h>
#include <Graphics/Material.h>
#include <Graphics/ShaderProgram.h>
#include <Managers/ManagersFacade.h>
#include <Camera/CameraManager.h>

#include <Components/CameraComponent.h>

namespace shen3
{
    void RenderQueue::Draw()
    {
        BeginFrame();
        Sort();
        ProcessCommands();
        ClearCommands();
        EndFrame();
    }

    void RenderQueue::AddCommand(RenderCommand&& command)
    {
        _commands.push_back(std::move(command));
    }

    void RenderQueue::ProcessCommands()
    {
        const auto cameraManager = ManagersFacade::Instance().GetManager<CameraManager>();
        auto camera = cameraManager->GetMainCamera();

        for (auto& command : _commands) {
            PrepareCommand(command, camera);
            ProcessCommand(command);
        }
    }

    void RenderQueue::PrepareCommand(RenderCommand& command, CameraComponent* camera)
    {
        command.material->SetParam("uModel", command.transform);
        command.material->SetParam("uView", camera->GetViewMatrix());
        command.material->SetParam("uProjection", camera->GetProjectionsMatrix());
    }

    void RenderQueue::ClearCommands()
    {
        _commands.clear();
    }

    void RenderQueue::Sort()
    {
        // TODO
    }
}
