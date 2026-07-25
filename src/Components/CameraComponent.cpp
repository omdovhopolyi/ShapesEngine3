#include <Components/CameraComponent.h>
#include <Math/Utils.h>
#include <Scene/SceneObject.h>

namespace shen3
{
    REGISTER_LOADER(CameraComponent)

    Mat4 CameraComponent::GetViewMatrix() const
    {
        return CreateViewMatrix(_sceneObject->GetWorldTransformMat());
    }

    Mat4 CameraComponent::GetProjectionsMatrix() const
    {
        const float ratio = static_cast<float>(1280) / static_cast<float>(720); // TODO get from render target

        return CreateProjectionsMatrix(_fov, ratio, _near, _far);
    }
}
