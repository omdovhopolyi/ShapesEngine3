#pragma once

#include <Components/Component.h>

namespace shen3
{
    class TestComponent
        : public Component
    {
    public:
        void OnActivated() override;
        void Update(float dt) override;

    private:
    };
}
