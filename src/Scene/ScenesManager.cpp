#include <Scene/ScenesManager.h>
#include <Managers/ManagersController.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(ScenesManager)

    void ScenesManager::Update()
    {
        float dt = GetManagers()->GetGameDt();

        for (auto& scene : _scenes) {
            if (scene) {
                scene->Update(dt);
            }
        }
    }
}
