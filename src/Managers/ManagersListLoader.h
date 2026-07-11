#pragma once

#include <vector>
#include <string>

namespace shen3
{
    class ManagersListLoader
    {
    public:
        bool Load();
        const std::vector<std::string>& GetManagersList() const;

    private:
        std::vector<std::string> _managersList;
    };
}
