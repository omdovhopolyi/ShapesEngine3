#include <OpenGL/OpenGLShaderProgram.h>

#include <glad/gl.h>

#include <glm/gtc/type_ptr.hpp>

namespace shen3
{
    OpenGLShaderProgram::OpenGLShaderProgram(unsigned int id)
        : ShaderProgram(id)
    {}

    int OpenGLShaderProgram::GetUniformLocation(const std::string& name)
    {
        auto it = _uniformLocationCache.find(name);
        if (it != _uniformLocationCache.end())
        {
            return it->second;
        }

        int location = glGetUniformLocation(_programId, name.c_str());
        _uniformLocationCache[name] = location;
        return location;
    }

    void OpenGLShaderProgram::SetUniform(const std::string& name, float value)
    {
        int location = GetUniformLocation(name);
        glUniform1f(location, value);
    }

    void OpenGLShaderProgram::SetUniform(const std::string& name, const Vec2& value)
    {
        int location = GetUniformLocation(name);
        glUniform2f(location, value.x, value.y);
    }

    void OpenGLShaderProgram::SetUniform(const std::string& name, const Mat4& value)
    {
        int location = GetUniformLocation(name);
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void OpenGLShaderProgram::Use() const
    {
        glUseProgram(_programId);
    }
}
