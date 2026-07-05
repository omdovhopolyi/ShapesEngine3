#pragma once

#include <Serialization/Loaders/LoaderBase.h>
#include <Serialization/Serializable.h>

namespace shen3
{
    /*template<class T>
    class LoaderECSComponent
        : public LoaderBase
    {
    public:
        std::shared_ptr<Serializable> CreateAndLoad(const DataElementWrapper& element) override
        {
            if (auto systems = element.GetSystems()) {
                if (auto mapLoaderSystem = systems->GetSystem<MapLoaderSystem>()) {
                    auto entity = mapLoaderSystem->GetCurrentLoadingEntity();
                    auto& world = systems->GetWorld();
                    if (world.IsValid(entity)) {
                        if (auto component = world.AddComponent<T>(entity)) {
                            component->RegisterProperties();
                            component->Load(element);
                            component->AfterLoad();
                        }
                    }
                }
            }

            return nullptr;
        }
    };*/
}
