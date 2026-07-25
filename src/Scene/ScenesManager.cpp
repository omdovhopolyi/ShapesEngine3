#include <Scene/ScenesManager.h>
#include <Managers/ManagersController.h>

#include <Components/MeshComponent.h>
#include <Graphics/MeshesManager.h>
#include <Graphics/MaterialsManager.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(ScenesManager)

    void ScenesManager::Start()
    {
        auto mesh = GetManagers()->GetManager<MeshesManager>()->GetMesh("square");
        auto material = GetManagers()->GetManager<MaterialsManager>()->GetMaterial("default");

        auto scene = std::make_unique<Scene>();

        auto sceneObject = scene->CreateSceneObject(nullptr, "root");
        auto meshComponent = sceneObject->AddComponent<MeshComponent>();
        meshComponent->SetMesh(mesh);
        meshComponent->SetMaterial(material);

        _scenes.emplace_back(std::move(scene));
    }

    void ScenesManager::Update()
    {
        float dt = GetManagers()->GetGameDt();

        for (auto& scene : _scenes) {
            if (scene) {
                scene->Update(dt);
            }
        }
    }
}
