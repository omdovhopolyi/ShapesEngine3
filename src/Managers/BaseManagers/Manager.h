#pragma once

#include <Managers/ManagersFactoryRegistration.h>
#include <typeindex>
#include <string>

namespace shen3
{
    class ManagersController;

    class Manager
    {
    public:
        virtual ~Manager() = default;

        virtual void Init(ManagersController* managersController);
        virtual void Load() {}
        virtual void Start() {}
        virtual void Save() {}
        virtual void Stop() {}

        virtual void AppActivated() {};
        virtual void AppDeactivated() {};

        virtual std::type_index GetTypeIndex() { return std::type_index(typeid(Manager)); }
        virtual std::string GetTypeName() { return {}; }

        ManagersController* GetSystems() const { return _managersController; }

    protected:
        ManagersController* _managersController = nullptr;
    };
}
