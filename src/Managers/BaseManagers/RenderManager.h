#pragma once

#include <Managers/BaseManagers/Manager.h>

namespace shen3
{
    class RenderManager
        : public Manager
    {
    public:
        virtual void BeginFrame() {}
        virtual void Draw() {}
        virtual void EndFrame() {}
    };
}
