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
}
