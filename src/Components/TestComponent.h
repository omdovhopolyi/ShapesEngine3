#pragma once

#include <Components/Component.h>

namespace shen3
{
    class TestComponent
        : public Component
    {
        SERIALIZABLE(TestComponent)

    public:
        void OnStarted() override;
        void Update(float dt) override;

    private:
    };
}
