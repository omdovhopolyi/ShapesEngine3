#pragma once

#include <Graphics/RenderQueue.h>

namespace shen3
{
    class OpenGLRenderQueue
        : public RenderQueue
    {
        MANAGERS_FACTORY(OpenGLRenderQueue)

    public:
        void BeginFrame() override;
        void EndFrame() override;

    protected:
        void ProcessCommand(const RenderCommand& command) override;
    };
}
