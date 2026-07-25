#pragma once

#include <Graphics/MeshesManager.h>

namespace shen3
{
    class OpenGLMeshesManager final
        : public MeshesManager
    {
        MANAGERS_FACTORY(MeshesManager)

    protected:
        void InitMeshes() override;
        std::unique_ptr<Mesh> CreateMesh(MeshData&& meshData) override;
    };
}
