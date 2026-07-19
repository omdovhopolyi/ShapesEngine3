#pragma once

#include <Graphics/MeshData.h>

namespace shen3
{
    class Mesh
    {
    public:
        Mesh(MeshData&& meshData);

        void InitBuffers(unsigned int vbo, unsigned int ebo, unsigned int vao);

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
