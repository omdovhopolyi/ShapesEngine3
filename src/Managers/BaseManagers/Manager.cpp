#include <Managers/BaseManagers/Manager.h>

namespace shen3
{
    void Manager::Init(ManagersController* managersController)
    {
        _managersController = managersController;
    }
}
