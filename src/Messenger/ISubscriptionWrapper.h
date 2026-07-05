#pragma once

namespace shen3
{
    struct Event;

    class ISubscriptionWrapper
    {
    public:
        virtual ~ISubscriptionWrapper() = default;

        virtual void Execute(const Event& event) = 0;
    };
}
