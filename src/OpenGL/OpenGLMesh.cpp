#include <OpenGL/OpenGLMesh.h>

#include <glad/gl.h>

namespace shen3
{
    OpenGLMesh::OpenGLMesh(MeshData&& meshData)
        : Mesh(std::move(meshData))
    {}

    void OpenGLMesh::Bind() const
    {
        glBindVertexArray(_vao);
    }

    void OpenGLMesh::Draw() const
    {
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_indicesCount), GL_UNSIGNED_INT, 0);
    }
}
