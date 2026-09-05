#include <OpenGL/OpenGLMeshesManager.h>
#include <OpenGL/OpenGLMesh.h>
#include <Logger/Logger.h>
#include <Math/Math.h>
#include <Common/Assert.h>
#include <Common/FilePath.h>

#include <glad/gl.h>

#include <fstream>
#include <format>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(OpenGLMeshesManager)

    void OpenGLMeshesManager::InitMeshes()
    {
        for (auto& [id, mesh] : _meshes) {
            if (mesh) {
                const auto& meshData = mesh->GetMeshData();
                
                unsigned int vbo = 0;
                unsigned int ebo = 0;
                unsigned int vao = 0;

                glGenVertexArrays(1, &vao);
                glGenBuffers(1, &vbo);
                glGenBuffers(1, &ebo);

                glBindVertexArray(vao);
                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBufferData(GL_ARRAY_BUFFER, meshData.vertices.size() * sizeof(MeshVertex), &meshData.vertices[0], GL_STATIC_DRAW);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshData.indices.size() * sizeof(unsigned int), &meshData.indices[0], GL_STATIC_DRAW);

                // vertex Positions
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)0);
                // vertex normals
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, normal));
                // vertex texture coords
                glEnableVertexAttribArray(2);
                glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, texCoords));
                // vertex tangent
                glEnableVertexAttribArray(3);
                glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, tangent));
                // vertex bitangent
                glEnableVertexAttribArray(4);
                glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, bitangent));
                // ids
                glEnableVertexAttribArray(5);
                glVertexAttribIPointer(5, 4, GL_INT, sizeof(MeshVertex), (void*)offsetof(MeshVertex, boneIDs));
                // weights
                glEnableVertexAttribArray(6);
                glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, weights));

                glBindVertexArray(0);

                mesh->InitBuffers(vbo, ebo, vao);
            }
        }
    }

    std::unique_ptr<Mesh> OpenGLMeshesManager::CreateMesh(MeshData&& meshData)
    {
        return std::make_unique<OpenGLMesh>(std::move(meshData));
    }
}