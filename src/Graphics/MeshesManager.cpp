#include <Graphics/MeshesManager.h>
#include <Serialization/DataElementWrapperFactory.h>
#include <Common/FilePath.h>

namespace shen3
{
    void MeshesManager::Load()
    {
        auto elementWrapper = DataElementWrapperFactory::Get(FilePath::Path("assets/configs/meshes.xml"));
        elementWrapper->ForAllChildren("mesh", [&](const DataElementWrapper& element) {
            const auto id = element.GetStr("id");
            const auto filename = element.GetStr("file");
            LoadMesh(id, filename);
        });
    }

    Mesh* MeshesManager::GetMesh(const std::string& id) const
    {
        auto it = _meshes.find(id);
        return (it != _meshes.end()) ? it->second.get() : nullptr;
    }

    void MeshesManager::AddMesh(const std::string& id, std::unique_ptr<Mesh> mesh)
    {
        _meshes[id] = std::move(mesh);
    }
}
