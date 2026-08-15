#include <Components/PlayerInputComponent.h>
#include <Messenger/Events/Common.h>
#include <Scene/SceneObject.h>
#include <Managers/ManagersFacade.h>
#include <Time/TimeManager.h>
#include <Managers/BaseManagers/PlayerWindowInputManager.h>
#include <Math/Utils.h>
#include <Logger/Logger.h>

namespace shen3
{
    REGISTER_LOADER(PlayerInputComponent)

    void PlayerInputComponent::OnInstantiated()
    {
        InitSubscriptions();
    }

    void PlayerInputComponent::Update(float dt)
    {

    }

    void PlayerInputComponent::InitSubscriptions()
    {
        // TODO proper configurable input

        _subscriptions.Subscribe<KeyEvent>([this](const KeyEvent& event) {
            if (event.type != InputEventType::Hold) {
                return;
            }

            auto managers = ManagersFacade::Instance().GetManagersController();
            auto time = managers->GetTime();
            const float dt = time.GameDt();

            auto transform = _sceneObject->GetLocalTransform();
            const auto forward = transform.GetForward();
            const auto right = transform.GetRight();

            const auto inputManager = managers->GetInput();
            const auto key = inputManager->GetCharByKey(event.code);

            if (key == "w") {
                transform.Translate(forward * _moveSpeed * dt);
            }
            else if (key == "s") {
                transform.Translate(-forward * _moveSpeed * dt);
            }
            else if (key == "d") {
                transform.Translate(right * _moveSpeed * dt);
            }
            else if (key == "a") {
                transform.Translate(-right * _moveSpeed * dt);
            }

            _sceneObject->SetLocalTransform(transform);

        });
        _subscriptions.Subscribe<MouseButtonEvent>([this](const MouseButtonEvent& event) {
            
        });
        _subscriptions.Subscribe<MouseMoveEvent>([this](const MouseMoveEvent& event) {
            auto managers = ManagersFacade::Instance().GetManagersController();
            auto time = managers->GetTime();
            const float dt = time.GameDt();

            const float xRotation = static_cast<float>(-event.dx) * _mouseSensitivity * dt;
            const float yRotation = static_cast<float>(-event.dy) * _mouseSensitivity * dt;

            auto transform = _sceneObject->GetLocalTransform();

            const auto worldUp = Vec3(0.f, 1.f, 0.f);
            const auto localRight = transform.GetRight();
            auto rotationY = CreateRotation(yRotation, localRight);
            auto rotationX = CreateRotation(xRotation, worldUp);
            auto rotation = rotationY * rotationX;
            transform.Rotate(rotation);
            _sceneObject->SetLocalTransform(transform);
        });
        _subscriptions.Subscribe<MouseWheelEvent>([this](const MouseWheelEvent& event) {

        });
    }
}
