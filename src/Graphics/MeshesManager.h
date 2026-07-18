#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Graphics/Mesh.h>

namespace shen3
{
    class MeshesManager
        : public Manager
    {
    public:
        void Load() override;
        Mesh* GetMesh(const std::string& id) const;
        void AddMesh(const std::string& id, std::unique_ptr<Mesh> mesh);

    protected:
        virtual void LoadMesh(const std::string& id, const std::string& filename) = 0;
    private:
        std::unordered_map<std::string, std::unique_ptr<Mesh>> _meshes;
    };
}
