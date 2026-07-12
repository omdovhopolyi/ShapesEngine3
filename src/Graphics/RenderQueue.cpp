#include <Graphics/RenderQueue.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(RenderQueue)

    void RenderQueue::Update()
    {
        Sort();
        ProcessCommands();
        ClearCommands();
    }

    void RenderQueue::AddCommand(RenderCommand& command)
    {
        _commands.push_back(std::move(command));
    }

    void RenderQueue::ProcessCommands()
    {
        for (auto& command : _commands) {
            command.Draw();
        }
    }

    void RenderQueue::ClearCommands()
    {
        _commands.clear();
    }

    void RenderQueue::Sort()
    {
        // TODO
    }
}
