#pragma once

#include <map>
#include <string>

#include <Common/Singleton.h>
#include <Serialization/Serializable.h>
#include <Serialization/Loaders/LoaderDefault.h>
#include <Serialization/Loaders/LoaderECSComponent.h>

namespace shen3
{
    class LoadersManager
        : public Singleton<LoadersManager>
    {
    public:
        void RegisterLoader(const std::shared_ptr<LoaderBase>& loader, const std::string& type)
        {
            _loaders.insert({ type, loader });
        }

        /*template<class T>
        void RegisterComponentLoader(const std::string& type)
        {
            _loaders.insert({ type, std::make_shared<LoaderECSComponent<T>>() });
        }*/

        std::shared_ptr<LoaderBase> GetLoader(const std::string& type);

    private:
        std::unordered_map<std::string, std::shared_ptr<LoaderBase>> _loaders;
    };
}
