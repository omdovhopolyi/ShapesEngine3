#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Common/Singleton.h>

#include <string>
#include <map>
#include <functional>
#include <memory>

namespace shen3
{
    class Manager;

    class ManagersFactory
        : public Singleton<ManagersFactory>
    {
    public:
        using FactoryFunc = std::function<std::unique_ptr<Manager>()>;

        void RegisterManagersFactory(const std::string& id, const FactoryFunc& factory);
        std::unique_ptr<Manager> Get(const std::string& id);

    private:
        std::map<std::string, FactoryFunc> _factories;
    };
}