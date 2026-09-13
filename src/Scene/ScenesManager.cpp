#include <Scene/ScenesManager.h>
#include <Managers/ManagersController.h>

#include <Components/MeshComponent.h>
#include <Components/CameraComponent.h>
#include <Components/PlayerInputComponent.h>
#include <Components/LightComponent.h>
#include <Graphics/MeshesManager.h>
#include <Graphics/MaterialsManager.h>
#include <Camera/CameraManager.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(ScenesManager)

    void ScenesManager::Start()
    {
        auto mesh = GetManagers()->GetManager<MeshesManager>()->GetMesh("cube");
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
        cameraTransform.SetPosition({ -0.5f, 1.f, 3.f });
        cameraObject->SetLocalTransform(cameraTransform);

        cameraObject->AddComponent<PlayerInputComponent>();

        cameraObject->OnInstantiated();
        
        auto cameraManager = GetManagers()->GetManager<CameraManager>();
        auto sharedCameraBase = camera->shared_from_this();
        auto sharedCamera = std::static_pointer_cast<CameraComponent>(sharedCameraBase);
        cameraManager->SetMainCamera(sharedCamera);

        auto lightObject = scene->CreateSceneObject(nullptr, "light");
        auto lightTransform = lightObject->GetLocalTransform();
        lightTransform.SetPosition({ 4.f, 2.f, 0.f });
        lightTransform.SetScale({ 0.2f, 0.2f, 0.2f });
        lightObject->SetLocalTransform(lightTransform);
        auto light = lightObject->AddComponent<LightComponent>();
        light->SetColor({ 0.f, 1.f, 0.5f });
        //lightObject->AddComponent<PlayerInputComponent>();
        auto lightMesh = lightObject->AddComponent<MeshComponent>();
        lightMesh->SetMesh(mesh);
        lightMesh->SetMaterial(material);

        lightObject->OnInstantiated();

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
