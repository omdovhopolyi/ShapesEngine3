#include <OpenGL/OpenGLRenderQueue.h>
#include <Graphics/RenderCommand.h>
#include <Graphics/ShaderProgram.h>
#include <Graphics/Mesh.h>
#include <Graphics/Material.h>
#include <Managers/ManagersController.h>
#include <SDL/SDLMainWindow.h>

#include <glad/gl.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(OpenGLRenderQueue)

    void OpenGLRenderQueue::BeginFrame()
    {
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGLRenderQueue::EndFrame()
    {
        GetManagers()->GetManager<SDLMainWindow>()->SwapBuffers();
    }

    void OpenGLRenderQueue::ProcessCommand(const RenderCommand& command)
    {
        command.material->Use();
        command.mesh->Bind();
        command.mesh->Draw();
    }
}
