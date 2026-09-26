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
        // TODO scene loading

        auto mesh = GetManagers()->GetManager<MeshesManager>()->GetMesh("cube");
        auto containerMesh = GetManagers()->GetManager<MeshesManager>()->GetMesh("container");

        auto material = GetManagers()->GetManager<MaterialsManager>()->GetMaterial("default");
        auto containerMat = GetManagers()->GetManager<MaterialsManager>()->GetMaterial("container");
        auto lightMat = GetManagers()->GetManager<MaterialsManager>()->GetMaterial("light");

        auto scene = std::make_unique<Scene>();

        auto sceneObject = scene->CreateSceneObject(nullptr, "test_object");
        auto meshComponent = sceneObject->AddComponent<MeshComponent>();
        meshComponent->SetMesh(containerMesh);
        meshComponent->SetMaterial(containerMat);
        sceneObject->OnInstantiated();

        auto cameraObject = scene->CreateSceneObject(nullptr, "camera");
        auto camera = cameraObject->AddComponent<CameraComponent>();
        auto cameraTransform = cameraObject->GetLocalTransform();
        cameraTransform.SetPosition({ -0.5f, 1.f, 3.f });
        cameraObject->SetLocalTransform(cameraTransform);
        cameraObject->AddComponent<PlayerInputComponent>();
        cameraObject->OnInstantiated();

        auto gunObject = scene->CreateSceneObject(cameraObject, "gun");
        auto gunTransform = gunObject->GetLocalTransform();
        gunTransform.SetPosition({ 1.f, 0.f, -2.f });
        gunTransform.SetScale({ 0.2f, 0.2f, 0.2f });
        gunObject->SetLocalTransform(gunTransform);
        auto gunMesh = gunObject->AddComponent<MeshComponent>();
        gunMesh->SetMesh(mesh);
        gunMesh->SetMaterial(material);
        gunObject->OnInstantiated();
        
        auto cameraManager = GetManagers()->GetManager<CameraManager>();
        auto sharedCameraBase = camera->shared_from_this();
        auto sharedCamera = std::static_pointer_cast<CameraComponent>(sharedCameraBase);
        cameraManager->SetMainCamera(sharedCamera);

        auto lightObject = scene->CreateSceneObject(nullptr, "light");
        auto lightTransform = lightObject->GetLocalTransform();
        lightTransform.SetPosition({ 3.f, 2.f, 0.f });
        lightTransform.SetScale({ 0.2f, 0.2f, 0.2f });
        lightObject->SetLocalTransform(lightTransform);
        auto light = lightObject->AddComponent<LightComponent>();
        light->SetColor({ 1.f, 1.f, 1.f });
        //lightObject->AddComponent<PlayerInputComponent>();
        auto lightMesh = lightObject->AddComponent<MeshComponent>();
        lightMesh->SetMesh(mesh);
        lightMesh->SetMaterial(lightMat);
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
