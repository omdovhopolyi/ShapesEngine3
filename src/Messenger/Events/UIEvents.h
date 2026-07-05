#pragma once

#include <string>
#include <Messenger/Events/Event.h>

namespace shen3
{
    struct OpenWindowEvent : Event
    {
        std::string windowId;

        OpenWindowEvent(const std::string& id) : windowId(id) {}
    };

    struct CloseWindowEvent : Event
    {
        std::string windowId;

        CloseWindowEvent(const std::string& id) : windowId(id) {}
    };

    struct CloseTopWindowEvent : Event {};
}
