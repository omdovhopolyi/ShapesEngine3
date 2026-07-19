#include <OpenGL/OpenGLMeshesManager.h>
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
                unsigned int ebo;
                unsigned int vao;

                glGenBuffers(1, &vbo);
                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBufferData(GL_ARRAY_BUFFER, meshData.vertices.size() * sizeof(Vec3), meshData.vertices.data(), GL_STATIC_DRAW);
                glBindBuffer(GL_ARRAY_BUFFER, 0);

                glGenBuffers(1, &ebo);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshData.indices.size() * sizeof(unsigned int), meshData.indices.data(), GL_STATIC_DRAW);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

                glGenVertexArrays(1, &vao);
                glBindVertexArray(vao);
                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3), (void*)0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindVertexArray(0);

                mesh->InitBuffers(vbo, ebo, vao);
            }
        }
    }
}