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

        CameraComponent* GetCamera(const std::string& cameraId) const;
        void SetCamera(const std::string& cameraId, std::weak_ptr<CameraComponent> camera);
        void RemoveCamera(const std::string& cameraId);

    private:
        std::weak_ptr<CameraComponent> _mainCamera;
        std::map<std::string, std::weak_ptr<CameraComponent>> _cameras;
    };
}
