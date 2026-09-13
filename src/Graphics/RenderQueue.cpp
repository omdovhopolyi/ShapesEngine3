#include <Graphics/RenderQueue.h>
#include <Graphics/Material.h>
#include <Graphics/ShaderProgram.h>
#include <Graphics/Mesh.h>
#include <Managers/ManagersFacade.h>
#include <Camera/CameraManager.h>
#include <Lights/LightsManager.h>
#include <Components/LightComponent.h>

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

        const auto lightsManager = ManagersFacade::Instance().GetManager<LightsManager>();
        const auto& lights = lightsManager->GetLights();

        for (auto& command : _commands) {
            PrepareCommand(command, camera);
            ProcessCommand(command);

            if (!lights.empty()) {
                const auto& light = *lights.begin();
                command.material->SetParam("uLight.position", light->GetPosition());
                command.material->SetParam("uLight.color", light->GetColor());
            }
            
            //TODO move to prepare command
            /*for (const auto& light : lights) {
            }*/
        }
    }

    void RenderQueue::PrepareCommand(RenderCommand& command, CameraComponent* camera)
    {
        command.material->SetParam("uModel", command.transform);
        command.material->SetParam("uView", camera->GetViewMatrix());
        command.material->SetParam("uProjection", camera->GetProjectionsMatrix());
    }

    void RenderQueue::ProcessCommand(const RenderCommand& command)
    {
        command.material->Use();
        command.mesh->Bind();
        command.mesh->Draw();
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
