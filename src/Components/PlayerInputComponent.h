#pragma once

#include <Components/Component.h>
#include <Messenger/SubscriptionsContainer.h>

namespace shen3
{
    class PlayerInputComponent
        : public Component
    {
        SERIALIZABLE(PlayerInputComponent)

    public:
        void OnInstantiated() override;
        void Update(float dt) override;

    private:
        void InitSubscriptions();

    private:
        float _mouseSensitivity = 1.f;
        float _moveSpeed = 1.f;

        SubcriptionsContainer _subscriptions;
    };
}
