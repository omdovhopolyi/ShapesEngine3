#pragma once

#include <Managers/BaseManagers/Manager.h>

#include <memory>

namespace shen3
{
    class CameraComponent;

    class CameraManager
        : public Manager
    {
        MANAGERS_FACTORY(CameraManager)

    public:
        void SetMainCamera(std::weak_ptr<CameraComponent> camera);
        CameraComponent* GetMainCamera() const;

    private:
        std::weak_ptr<CameraComponent> _mainCamera;
    };
}
