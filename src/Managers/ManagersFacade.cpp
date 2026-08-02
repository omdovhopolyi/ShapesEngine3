#include <Managers/ManagersFacade.h>

namespace shen3
{
    void ManagersFacade::Init(ManagersController* managersController)
    {
        _managersController = managersController;
    }

    ManagersController* ManagersFacade::GetManagersController() const
    {
        return _managersController;
    }
}
