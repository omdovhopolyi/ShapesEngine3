#pragma once

#include <Graphics/MeshData.h>

namespace shen3
{
    class Mesh
    {
    public:
        Mesh(unsigned int vbo, unsigned int ebo, unsigned int vao, MeshData&& meshData);

        void Bind() const;
        void Draw() const;

        unsigned int GetVAO() const;
        unsigned int GetVBO() const;
        unsigned int GetEBO() const;

        MeshData& GetMeshData();

    private:
        MeshData _meshData;

        unsigned int _vbo = 0;
        unsigned int _ebo = 0;
        unsigned int _vao = 0;
    };
}
