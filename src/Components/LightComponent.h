#pragma once

#include <Components/Component.h>
#include <Math/Vec4.h>

namespace shen3
{
    class LightComponent
        : public Component
    {
        SERIALIZABLE(LightComponent)

    public:
        void OnStarted() override;
        void Update(float dt) override;
        void OnDeactivated() override;

        Vec3 GetPosition() const;

        void SetColor(const Vec3& color);
        Vec3 GetColor() const;

        void SetOn(bool on);
        bool IsOn() const;

    protected:
        void Register();
        void Unregister();

    protected:
        Vec3 _color = Vec3(1.f);
        bool _isOn = true;
    };
}
