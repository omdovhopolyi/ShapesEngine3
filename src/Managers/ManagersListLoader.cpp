#include <Managers/ManagersListLoader.h>
#include <Serialization/WrapperTypes/XmlDataElementWrapper.h>
#include <Common/Assert.h>
#include <Common/FilePath.h>

namespace shen3
{
    bool ManagersListLoader::Load()
    {
        _managersList.clear();

        auto elementWrapper = XmlDataElementWrapper{ nullptr };
        elementWrapper.LoadFile(FilePath::Path("assets/configs/managers.xml"));
        elementWrapper.ForAllChildren("manager", [&](const DataElementWrapper& element) {
            const auto managerType = element.GetStr("type");
            _managersList.push_back(managerType);
        });

        return true;
    }

    const std::vector<std::string>& ManagersListLoader::GetManagersList() const
    {
        return _managersList;
    }
}
