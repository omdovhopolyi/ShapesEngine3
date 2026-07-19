#pragma once

#include <Graphics/MeshesManager.h>

namespace shen3
{
    class OpenGLMeshesManager
        : public MeshesManager
    {
        MANAGERS_FACTORY(OpenGLMeshesManager)

    protected:
        void InitMeshes() override;
    };
}
