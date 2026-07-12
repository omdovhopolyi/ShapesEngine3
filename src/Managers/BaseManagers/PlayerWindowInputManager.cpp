#include <Managers/BaseManagers/PlayerWindowInputManager.h>

namespace shen3
{
    void PlayerWindowInputManager::Start()
    {
        GenerateCharKeyMap();
        GenerateKeyCharMap();
    }

    void PlayerWindowInputManager::GenerateKeyCharMap()
    {
        _keyCharMap.clear();
        for (const auto& [str, key] : _charKeyMap) {
            _keyCharMap[key] = str;
        }
    }
}
