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

                unsigned int vbo;
                unsigned int texVbo;
                unsigned int ebo;
                unsigned int vao;

                glGenVertexArrays(1, &vao);
                glBindVertexArray(vao);

                glGenBuffers(1, &vbo);
                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBufferData(GL_ARRAY_BUFFER, meshData.vertices.size() * sizeof(Vec3), meshData.vertices.data(), GL_STATIC_DRAW);
                glBindBuffer(GL_ARRAY_BUFFER, 0);

                glGenBuffers(1, &texVbo);
                glBindBuffer(GL_ARRAY_BUFFER, texVbo);
                glBufferData(GL_ARRAY_BUFFER, meshData.texCoords.size() * sizeof(Vec2), meshData.texCoords.data(), GL_STATIC_DRAW);
                glBindBuffer(GL_ARRAY_BUFFER, 0);

                glGenBuffers(1, &ebo);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshData.indices.size() * sizeof(unsigned int), meshData.indices.data(), GL_STATIC_DRAW);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3), (void*)0);
                glEnableVertexAttribArray(0);

                glBindBuffer(GL_ARRAY_BUFFER, texVbo);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2), (void*)0);
                glEnableVertexAttribArray(1);

                glBindVertexArray(0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);

                mesh->InitBuffers(vbo, ebo, vao);
            }
        }
    }

    std::unique_ptr<Mesh> OpenGLMeshesManager::CreateMesh(MeshData&& meshData)
    {
        return std::make_unique<OpenGLMesh>(std::move(meshData));
    }
}