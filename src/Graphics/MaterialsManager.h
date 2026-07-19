#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Graphics/Material.h>

namespace shen3
{
    class DataElementWrapper;

    class MaterialsManager
        : public Manager
    {
        MANAGERS_FACTORY(MaterialsManager)

    public:
        void Load() override;

        Material* GetMaterial(const std::string& id) const;
        void AddMaterial(const std::string& id, std::unique_ptr<Material> material);

    protected:
        void LoadMaterial(const std::string& id, const std::string& filename);

    protected:
        std::unordered_map<std::string, std::unique_ptr<Material>> _materials;
    };
}