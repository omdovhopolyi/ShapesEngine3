#include <Lights/LightsManager.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(LightsManager)

    void LightsManager::RegisterLight(const std::shared_ptr<LightComponent>& component)
    {
        _lights.insert(component);
    }

    void LightsManager::RemoveLight(const std::shared_ptr<LightComponent>& component)
    {
        _lights.erase(component);
    }

    const std::unordered_set<std::shared_ptr<LightComponent>>& LightsManager::GetLights() const
    {
        return _lights;
    }
}
