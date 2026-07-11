#include <Managers/BaseManagers/PlayerWindowInputManager.h>

namespace shen3
{
    void PlayerWindowInputManager::Start()
    {
        GenerateCharKeyMap();
        GenerateKeyCharMap();
    }
}
