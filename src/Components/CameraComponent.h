#pragma once

#include <Components/Component.h>
#include <Math/Mat.h>
#include <Messenger/SubscriptionsContainer.h>

namespace shen3
{
    class CameraComponent final
        : public Component
    {
        SERIALIZABLE(CameraComponent)

    public:
        void OnInstantiated() override;

        void RequestWindowSize();

        Mat4 GetViewMatrix() const;
        Mat4 GetProjectionsMatrix() const;

    private:
        void InitSubscriptions();

        void OnWindowSizeChanged(int width, int height);

    private:
        float _fov = 45.f;
        float _near = 0.1f;
        float _far = 1000.f;
        float _ratio = 1.f;

        SubcriptionsContainer _subscriptions;
    };
}
