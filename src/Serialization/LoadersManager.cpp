#include <Serialization/LoadersManager.h>

namespace shen3
{
    std::shared_ptr<LoaderBase> LoadersManager::GetLoader(const std::string& type)
    {
        if (auto it = _loaders.find(type); it != _loaders.end()) {
            return it->second;
        }

        return nullptr;
    }
}
