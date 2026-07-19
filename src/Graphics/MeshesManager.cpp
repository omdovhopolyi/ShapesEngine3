#include <Graphics/MeshesManager.h>
#include <Serialization/DataElementWrapperFactory.h>
#include <Common/FilePath.h>
#include <Common/Assert.h>
#include <Logger/Logger.h>

#include <fstream>
#include <format>

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

    void MeshesManager::Start()
    {
        InitMeshes();
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

    void MeshesManager::LoadMesh(const std::string& id, const std::string& filename)
    {
        std::ifstream file(FilePath::Path(filename));

        if (!file.is_open()) {
            Logger::Log("[OpenGLMeshesManager::LoadMesh] Unable to open file: {}", filename);
            return;
        }

        MeshData meshData;

        std::string line;

        while (getline(file, line)) {
            if (strncmp(line.c_str(), "v ", 2) == 0) {
                Vec3 vertex;
                (void)sscanf_s(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
                meshData.vertices.push_back(vertex);
            }
            // tex coords info
            if (strncmp(line.c_str(), "vt ", 3) == 0) {
                Vec2 texCoord;
                (void)sscanf_s(line.c_str(), "vt %f %f", &texCoord.x, &texCoord.y);
                meshData.texCoords.push_back(texCoord);
            }
            // faces info
            if (strncmp(line.c_str(), "f ", 2) == 0) {
                int vertIndices[4];
                int texIndices[4];
                int normIndices[4];
                int count = sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
                    &vertIndices[0], &texIndices[0], &normIndices[0],
                    &vertIndices[1], &texIndices[1], &normIndices[1],
                    &vertIndices[2], &texIndices[2], &normIndices[2],
                    &vertIndices[3], &texIndices[3], &normIndices[3]
                );
                if (count == 9) { // triangle
                    Face face = {
                        .a = vertIndices[0] - 1,
                        .b = vertIndices[1] - 1,
                        .c = vertIndices[2] - 1,
                        .aUV = meshData.texCoords[texIndices[0] - 1],
                        .bUV = meshData.texCoords[texIndices[1] - 1],
                        .cUV = meshData.texCoords[texIndices[2] - 1],
                        .color = 0xFFFFFFFF
                    };
                    meshData.faces.push_back(face);

                    meshData.indices.push_back(face.a);
                    meshData.indices.push_back(face.b);
                    meshData.indices.push_back(face.c);

                    meshData.uvs.push_back(face.aUV);
                    meshData.uvs.push_back(face.bUV);
                    meshData.uvs.push_back(face.cUV);
                }
                else {
                    Assert(false, std::format("[OpenGLMeshesManager::LoadMesh] Only triangle faces are supported. Mesh: {}", filename));
                }
            }
        }

        file.close();

        auto mesh = std::make_unique<Mesh>(std::move(meshData));
        AddMesh(id, std::move(mesh));
    }
}
