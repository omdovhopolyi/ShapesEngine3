#pragma once

#include <Components/Component.h>
#include <Math/Mat.h>

namespace shen3
{
    class CameraComponent final
        : public Component
    {
        SERIALIZABLE(CameraComponent)

    public:
        Mat4 GetViewMatrix() const;
        Mat4 GetProjectionsMatrix() const;

    private:
        float _fov = 45.f;
        float _near = 0.1f;
        float _far = 1000.f;
    };
}
