#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Math/Vec.h>

#include <unordered_set>

namespace shen3
{
    class LightComponent;

    struct LightData
    {
        Vec3 position;
        Vec4 color;
    };

    class LightsManager
        : public Manager
    {
        MANAGERS_FACTORY(LightsManager)

    public:
        void RegisterLight(const std::shared_ptr<LightComponent>& component);
        void RemoveLight(const std::shared_ptr<LightComponent>& component);

        const std::unordered_set<std::shared_ptr<LightComponent>>& GetLights() const;

    private:
        std::unordered_set<std::shared_ptr<LightComponent>> _lights;
    };
}
