#include <Graphics/RenderQueue.h>

namespace shen3
{
    void RenderQueue::Draw()
    {
        BeginFrame();
        Sort();
        ProcessCommands();
        ClearCommands();
        EndFrame();
    }

    void RenderQueue::AddCommand(const RenderCommand& command)
    {
        _commands.push_back(std::move(command));
    }

    void RenderQueue::ProcessCommands()
    {
        for (const auto& command : _commands) {
            ProcessCommand(command);
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
