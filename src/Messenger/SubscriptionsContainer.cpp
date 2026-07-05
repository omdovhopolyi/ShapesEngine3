#include <Messenger/SubscriptionsContainer.h>

namespace shen3
{
    SubcriptionsContainer::~SubcriptionsContainer()
    {
        Reset();
    }

    void SubcriptionsContainer::Reset()
    {
        for (auto& [typeIndex, ptr] : _subscriptions) {
            Messenger::Instance().RemoveSubscription(typeIndex, ptr);
        }
        _subscriptions.clear();
    }
}
