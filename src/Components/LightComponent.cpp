#include <Components/LightComponent.h>

#include <Lights/LightsManager.h>

#include <Graphics/RenderQueue.h>
#include <Math/Transform.h>
#include <Scene/Scene.h>
#include <Managers/ManagersFacade.h>

namespace shen3
{
    REGISTER_LOADER(LightComponent);

    void LightComponent::OnStarted()
    {
        Register();
    }

    void LightComponent::Update(float)
    {
        //
    }

    void LightComponent::OnDeactivated()
    {
        Unregister();
    }

    Vec3 LightComponent::GetPosition() const
    {
        return _sceneObject->GetWorldPosition();
    }

    void LightComponent::SetColor(const Vec3& color)
    {
        _color = color;
    }

    Vec3 LightComponent::GetColor() const
    {
        return _color;
    }

    void LightComponent::SetOn(bool on)
    {
        if (_isOn != on) {
            _isOn = on;
            if (_isOn) {
                Register();
            }
            else {
                Unregister();
            }
        }
    }

    bool LightComponent::IsOn() const
    {
        return _isOn;
    }

    void LightComponent::Register()
    {
        if (auto manager = ManagersFacade::Instance().GetManager<LightsManager>()) {
            manager->RegisterLight(std::static_pointer_cast<LightComponent>(shared_from_this()));
        }
    }

    void LightComponent::Unregister()
    {
        if (auto manager = ManagersFacade::Instance().GetManager<LightsManager>()) {
            manager->RemoveLight(std::static_pointer_cast<LightComponent>(shared_from_this()));
        }
    }
}
