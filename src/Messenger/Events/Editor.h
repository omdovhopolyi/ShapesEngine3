#pragma once

#include <Messenger/Events/Event.h>

namespace shen3
{
    struct OpenEditor : Event { };

    struct CloseEditor : Event { };
}