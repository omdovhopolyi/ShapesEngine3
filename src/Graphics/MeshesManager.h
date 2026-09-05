#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Graphics/Mesh.h>

struct aiNode;
struct aiScene;
struct aiMesh;

namespace shen3
{
    class MeshesManager
        : public Manager
    {
    public:
        void Load() override;
        void Start() override;
        Mesh* GetMesh(const std::string& id) const;
        void AddMesh(const std::string& id, std::unique_ptr<Mesh> mesh);

    protected:
        virtual void LoadMesh(const std::string& id, const std::string& filename);
        virtual void InitMeshes() = 0;
        virtual std::unique_ptr<Mesh> CreateMesh(MeshData&& meshData) = 0;

        void ProcessNode(const std::string& id, aiNode* node, const aiScene* scene);
        void ProcessMesh(const std::string& id, aiMesh* mesh, const aiScene* scene);

    protected:
        std::unordered_map<std::string, std::unique_ptr<Mesh>> _meshes;
    };
}
