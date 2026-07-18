#include <OpenGL/OpenGLRenderQueue.h>
#include <Graphics/RenderCommand.h>
#include <Graphics/ShaderProgram.h>
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

        /*glUseProgram(_shaderProgram);
        glBindVertexArray(_vao);
        glUniform4f(_uColor, 0.f, 1.f, 0.f, 1.f);
        glUniform2f(_uOffset, _offset.x, _offset.y);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);*/
    }
}
