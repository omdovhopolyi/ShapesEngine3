#include <OpenGL/OpenGLShadersManager.h>
#include <OpenGL/OpenGLShaderProgram.h>
#include <Logger/Logger.h>

#include <glad/gl.h>

#include <format>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(OpenGLShadersManager)

    std::unique_ptr<ShaderProgram> OpenGLShadersManager::CreateShaderProgram(unsigned int shaderId)
    {
        return std::make_unique<OpenGLShaderProgram>(shaderId);
    }

    unsigned int OpenGLShadersManager::CreateShaderVertex()
    {
        return glCreateShader(GL_VERTEX_SHADER);
    }

    unsigned int OpenGLShadersManager::CreateShaderFragment()
    {
        return glCreateShader(GL_FRAGMENT_SHADER);
    }

    unsigned int OpenGLShadersManager::LoadShaderFromSource(unsigned int shaderId, const std::string& source)
    {
        const char* shaderCStr = source.c_str();
        glShaderSource(shaderId, 1, &shaderCStr, nullptr);
        glCompileShader(shaderId);

        GLint success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
            Logger::Err("[ShadersManager::LoadShaderFromSource] Can not compile shader: {}", infoLog);
            return 0U;
        }

        return shaderId;
    }

    unsigned int OpenGLShadersManager::CompileShader(unsigned int vertexShaderId, unsigned int fragmentShaderId)
    {
        unsigned int shaderId = glCreateProgram();
        glAttachShader(shaderId, vertexShaderId);
        glAttachShader(shaderId, fragmentShaderId);
        glLinkProgram(shaderId);

        GLint success;
        glGetProgramiv(shaderId, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(shaderId, 512, nullptr, infoLog);
            Logger::Err("[ShadersManager::CompileShader] Can not link shader: {}", infoLog);
            return 0U;
        }
        return shaderId;
    }

    void OpenGLShadersManager::ClearShader(unsigned int vertexShaderId, unsigned int fragmentShaderId)
    {
        glCompileShader(vertexShaderId);
        glCompileShader(fragmentShaderId);
    }
}
