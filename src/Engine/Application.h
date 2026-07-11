#pragma once

namespace shen3
{
    class Application
    {
    public:
        virtual void Init() = 0;
        virtual void Update(float dt) = 0;
        virtual void Shutdown() = 0;
    };
}
