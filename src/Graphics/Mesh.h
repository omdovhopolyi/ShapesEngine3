#pragma once

#include <Graphics/MeshData.h>

namespace shen3
{
    class Mesh
    {
    public:
        Mesh(MeshData&& meshData);
        virtual ~Mesh() = default;

        void InitBuffers(unsigned int vbo, unsigned int ebo, unsigned int vao);

        virtual void Bind() const = 0;
        virtual void Draw() const = 0;

        unsigned int GetVAO() const;
        unsigned int GetVBO() const;
        unsigned int GetEBO() const;

        MeshData& GetMeshData();

    protected:
        MeshData _meshData;
        int _indicesCount = 0;

        unsigned int _vbo = 0;
        unsigned int _ebo = 0;
        unsigned int _vao = 0;
    };
}
