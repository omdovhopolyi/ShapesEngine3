#include <Scene/ScenesManager.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(ScenesManager)

    void ScenesManager::Update()
    {
        for (auto& scene : _scenes) {
            if (scene) {
                scene->Update(0.f); // TODO dt
            }
        }
    }
}
