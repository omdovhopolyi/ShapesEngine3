#pragma once

#include <Common/Singleton.h>
#include <Managers/ManagersController.h>

namespace shen3
{
    class ManagersController;

    class ManagersFacade
        : public Singleton<ManagersFacade>
    {
    public:
        void Init(ManagersController* managersController);

        template<class T>
        T* GetManager() const;

    private:
        ManagersController* _managersController = nullptr;
    };

    template<class T>
    T* ManagersFacade::GetManager() const
    {
        if (_managersController) {
            return _managersController->GetManager<T>();
        }
        return nullptr;
    }
}