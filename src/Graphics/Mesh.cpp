#include <Graphics/Mesh.h>

namespace shen3
{
    Mesh::Mesh(MeshData&& meshData)
        : _meshData(std::move(meshData))
        , _indicesCount(static_cast<int>(_meshData.indices.size()))
    {}

    void Mesh::InitBuffers(unsigned int vbo, unsigned int ebo, unsigned int vao)
    {
        _vbo = vbo;
        _ebo = ebo;
        _vao = vao;
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
