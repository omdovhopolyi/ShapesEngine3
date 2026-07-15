#pragma once

#include <Graphics/ShadersManager.h>
#include <Managers/ManagersFactoryRegistration.h>

namespace shen3
{
    class OpenGLShadersManager
        : public ShadersManager
    {
        MANAGERS_FACTORY(OpenGLShadersManager)

    protected:
        unsigned int CreateShaderVertex() override;
        unsigned int CreateShaderFragment() override;
        unsigned int LoadShaderFromSource(unsigned int shaderId, const std::string& source) override;
        unsigned int CompileShader(unsigned int vertexShaderId, unsigned int fragmentShaderId) override;
        void ClearShader(unsigned int vertexShaderId, unsigned int fragmentShaderId) override;
    };
}
