#include <Managers/ManagersFactory.h>
#include <Logger/Logger.h>
#include <Common/Assert.h>
#include <format>

namespace shen3
{
    void ManagersFactory::RegisterManagersFactory(const std::string& id, const ManagersFactory::FactoryFunc& factory)
    {
        auto [it, isRegistered] = _factories.insert({ id, factory });
        if (!isRegistered){
            Logger::Log("[ManagersFactory::RegisterManagersFactory] Can not register managers factory {}", id);
        }
    }

    std::unique_ptr<Manager> ManagersFactory::Get(const std::string& id)
    {
        if (auto it = _factories.find(id); it != _factories.end()) {
            return it->second();
        }

        const auto msg = std::format("[ManagersFactory::RegisterManagerFactory] No factory for type '{}'", id);
        Assert(false, msg);
        return nullptr;
    }
}