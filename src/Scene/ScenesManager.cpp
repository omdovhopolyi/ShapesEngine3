#include <Scene/ScenesManager.h>
#include <Managers/ManagersController.h>

#include <Components/MeshComponent.h>
#include <Components/CameraComponent.h>
#include <Graphics/MeshesManager.h>
#include <Graphics/MaterialsManager.h>
#include <Camera/CameraManager.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(ScenesManager)

    void ScenesManager::Start()
    {
        auto mesh = GetManagers()->GetManager<MeshesManager>()->GetMesh("square");
        auto material = GetManagers()->GetManager<MaterialsManager>()->GetMaterial("default");

        auto scene = std::make_unique<Scene>();

        auto sceneObject = scene->CreateSceneObject(nullptr, "test_object");
        auto meshComponent = sceneObject->AddComponent<MeshComponent>();
        meshComponent->SetMesh(mesh);
        meshComponent->SetMaterial(material);
        sceneObject->OnInstantiated();

        auto cameraObject = scene->CreateSceneObject(nullptr, "camera");
        auto camera = cameraObject->AddComponent<CameraComponent>();
        auto cameraTransform = cameraObject->GetLocalTransform();
        cameraTransform.SetPosition({ 0.f, 0.f, 3.f }, true);
        cameraObject->SetLocalTransform(cameraTransform);
        cameraObject->OnInstantiated();
        
        auto cameraManager = GetManagers()->GetManager<CameraManager>();
        auto sharedCameraBase = camera->shared_from_this();
        auto sharedCamera = std::static_pointer_cast<CameraComponent>(sharedCameraBase);
        cameraManager->SetMainCamera(sharedCamera);

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
