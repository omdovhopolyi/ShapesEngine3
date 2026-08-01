#include <Camera/CameraManager.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(CameraManager)

    void CameraManager::SetMainCamera(std::weak_ptr<CameraComponent> camera)
    {
        _mainCamera = camera;
    }

    CameraComponent* CameraManager::GetMainCamera() const
    {
        if (auto camera = _mainCamera.lock()) {
            return camera.get();
        }
        return nullptr;
    }

    CameraComponent* CameraManager::GetCamera(const std::string& cameraId) const
    {
        if (auto it = _cameras.find(cameraId); it != _cameras.end()) {
            if (auto camera = it->second.lock()) {
                return camera.get();
            }
        }
        return nullptr;
    }

    void CameraManager::SetCamera(const std::string& cameraId, std::weak_ptr<CameraComponent> camera)
    {
        _cameras[cameraId] = camera;
    }

    void CameraManager::RemoveCamera(const std::string& cameraId)
    {
        _cameras.erase(cameraId);
    }
}
