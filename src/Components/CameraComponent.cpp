#include <Components/CameraComponent.h>
#include <Math/Utils.h>
#include <Scene/SceneObject.h>
#include <Messenger/Messenger.h>
#include <Messenger/Events/Common.h>

namespace shen3
{
    REGISTER_LOADER(CameraComponent)

    void CameraComponent::OnInstantiated()
    {
        InitSubscriptions();
        RequestWindowSize();
    }

    void CameraComponent::RequestWindowSize()
    {
        Messenger::Instance().Broadcast<RequestMainWindowSize>();
    }

    Mat4 CameraComponent::GetViewMatrix() const
    {
        return CreateViewMatrix(_sceneObject->GetWorldTransformMat());
    }

    Mat4 CameraComponent::GetProjectionsMatrix() const
    {
        return CreateProjectionsMatrix(_fov, _ratio, _near, _far);
    }

    void CameraComponent::InitSubscriptions()
    {
        _subscriptions.Subscribe<WindowResized>([this](const auto& event) {
            OnWindowSizeChanged(event.width, event.height);
        });
    }

    void CameraComponent::OnWindowSizeChanged(int width, int height)
    {
        _ratio = static_cast<float>(width) / static_cast<float>(height);
    }
}
