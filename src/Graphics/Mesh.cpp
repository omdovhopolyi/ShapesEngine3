#include <Graphics/Mesh.h>

namespace shen3
{
    Mesh::Mesh(MeshData&& meshData)
        : _meshData(std::move(meshData))
    {}

    void Mesh::InitBuffers(unsigned int vbo, unsigned int ebo, unsigned int vao)
    {
        _vbo = vbo;
        _ebo = ebo;
        _vao = vao;
    }

    void Mesh::Bind() const
    {
        // Implementation for binding the mesh
    }

    void Mesh::Draw() const
    {
        // Implementation for drawing the mesh
    }

    unsigned int Mesh::GetVAO() const
    {
        return _vao;
    }

    unsigned int Mesh::GetVBO() const
    {
        return _vbo;
    }

    unsigned int Mesh::GetEBO() const
    {
        return _ebo;
    }

    MeshData& Mesh::GetMeshData()
    {
        return _meshData;
    }
}
