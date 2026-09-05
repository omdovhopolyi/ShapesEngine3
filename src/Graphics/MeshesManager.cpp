#include <Graphics/MeshesManager.h>
#include <Serialization/DataElementWrapperFactory.h>
#include <Common/FilePath.h>
#include <Common/Assert.h>
#include <Logger/Logger.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <fstream>
#include <format>
#include <cstdio>

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
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(FilePath::Path(filename), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            const char* error = importer.GetErrorString();
            Logger::Err("[OpenGLMeshesManager::LoadMesh] Assimp error: {}", error);
            return;
        }
        
        ProcessNode(id, scene->mRootNode, scene);
    }

    void MeshesManager::ProcessNode(const std::string& id, aiNode* node, const aiScene* scene)
    {
        if (node->mNumChildren == 0) {
            return;
        }

        if (node->mNumMeshes == 1 || node->mNumChildren > 1) {
            Logger::Err("[MeshesManager::ProcessNode] There are unprocessed meshes for mesh id {}", id);
        }


        aiNode* childNode = node->mChildren[0];
        aiMesh* mesh = scene->mMeshes[childNode->mMeshes[0]];
        ProcessMesh(id, mesh, scene);
    }

    void MeshesManager::ProcessMesh(const std::string& id, aiMesh* mesh, const aiScene* scene)
    {
        MeshData meshData;

        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            MeshVertex vertex;
            // positions
            vertex.position.x = mesh->mVertices[i].x;
            vertex.position.y = mesh->mVertices[i].y;
            vertex.position.z = mesh->mVertices[i].z;
            // normals
            if (mesh->HasNormals())
            {
                vertex.normal.x = mesh->mNormals[i].x;
                vertex.normal.y = mesh->mNormals[i].y;
                vertex.normal.z = mesh->mNormals[i].z;
            }
            // texture coordinates
            if (mesh->mTextureCoords[0])
            {
                vertex.texCoords.x = mesh->mTextureCoords[0][i].x;
                vertex.texCoords.y = mesh->mTextureCoords[0][i].y;
                // tangent
                vertex.tangent.x = mesh->mTangents[i].x;
                vertex.tangent.y = mesh->mTangents[i].y;
                vertex.tangent.z = mesh->mTangents[i].z;
                // bitangent
                vertex.bitangent.x = mesh->mBitangents[i].x;
                vertex.bitangent.y = mesh->mBitangents[i].y;
                vertex.bitangent.z = mesh->mBitangents[i].z;
            }
            else {
                vertex.texCoords = Vec2(0.0f, 0.0f);
            }

            meshData.vertices.push_back(vertex);
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++) {
                meshData.indices.push_back(face.mIndices[j]);
            }
        }

        AddMesh(id, CreateMesh(std::move(meshData)));
    }
}
