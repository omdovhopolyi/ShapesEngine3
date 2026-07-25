#pragma once

#include <Graphics/Mesh.h>

namespace shen3
{
    class OpenGLMesh final
        : public Mesh
    {
    public:
        OpenGLMesh(MeshData&& meshData);

        void Bind() const override;
        void Draw() const override;
    };
}